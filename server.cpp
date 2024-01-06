#include <sstream>
#include <chrono>
#include <ctime>
#include <fstream>
#include "server.h"

Server::Server(int portNum) : port(portNum) {
    // Načítanie otázok
    if (!questionManager.loadQuestionsFromFile()) {
        std::cout << "Nepodarilo sa nacitat otazky." << std::endl;
    }
}

Server::~Server() {
    // Clean up sockets
    close(serverSocket);
    close(acceptSocket);

    // Cleanup Winsock
    // WSACleanup(); // Toto je nutné jen na Windows

    // Join all client threads before destruction
    for (auto& thread : clientThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}


bool Server::setupServerSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cout << "Nastala chyba pri sockete." << std::endl;
        return false;
    } else {
        std::cout << "Socket sa podarilo nacitat." << std::endl;
        return true;
    }
}

bool Server::bindSocket() {
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("frios2.fri.uniza.sk"); // IP adresa
    service.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&service, sizeof(service)) == -1) {
        std::cout << "bind sa nepodaril." << std::endl;
        close(serverSocket);
        return false;
    } else {
        std::cout << "Bind prebehol v poriadku." << std::endl;
        return true;
    }
}

bool Server::startListening() {
    if (listen(serverSocket, 1) == -1) {
        std::cout << "Chyba pri listeningu na sockete." << std::endl;
        return false;
    } else {
        std::cout << "Listen je v poriadku, cakam na nove pripojenie od klienta..." << std::endl;
        return true;
    }
}

bool Server::acceptConnection() {
    acceptSocket = accept(serverSocket, NULL, NULL);
    if (acceptSocket == -1) {
        std::cout << "Prijatie pripojenia sa nepodarilo." << std::endl;
        return false;
    } else {
        std::cout << "Vytvorilo sa nove pripojenie" << std::endl;

        std::thread clientThread(&Server::handleClient, this, acceptSocket);
        clientThread.detach(); // Oddelenie vlákna od hlavného vlákna

        return true;
    }
}

bool Server::startServer() {
    if (!setupServerSocket() || !bindSocket() || !startListening()) {
        cleanUp();
        return false;
    }

    while (true) {
        if (!acceptConnection()) {
            cleanUp();
            return false;
        }
    }

    return true;
}

std::string Server::GetClientName(int clientSocket) {
    char requestClientName[200] = "\n\nVitajte v tomto vedomostnom kvize.\nZadajte svoje meno.";
    send(clientSocket, requestClientName, strlen(requestClientName), 0);
    char clientName[201] = ""; // Leave space for the null terminator
    recv(clientSocket, clientName, 200, 0);

    return std::string(clientName);
}

void Server::sendPreviousGameResultsToClient(int clientSocket) {
    std::lock_guard<std::mutex> lock(fileMutex); // Lock to ensure synchronized access
    std::ifstream file("gameResults.txt");
    if (file.is_open()) {
        std::stringstream buffer;
        std::string line;
        while (std::getline(file, line)) {
            buffer << line << "\n"; // Uložím každý riadok do buffera
        }
        file.close();

        std::string allLines = buffer.str(); // všetky výsledky ako jeden string získam
        if (!allLines.empty()) {
            // Odoslanie výsledkov hier
            send(clientSocket, allLines.c_str(), allLines.length(), 0);
        } else {
            std::string errorMessage = "Ziadne hry este neboli odohrane.";
            send(clientSocket, errorMessage.c_str(), errorMessage.length(), 0);
        }
    } else {
        std::string errorMessage = "Nemozne otvorit subor: gameResults.txt";
        send(clientSocket, errorMessage.c_str(), errorMessage.length(), 0);
    }
}

bool Server::WelcomeNewClient(const std::string& clientName, int clientSocket) {
    std::cout << std::endl;
    std::string welcomeMessage = "\n" + clientName + " zvol si moznost, ako chces pokracovat:\nSpustit Hru - stlac 1 \nZobrazit vysledky hier - stlac 2 \nUkoncit hru - stlac cokolvek ine.";
    send(clientSocket, welcomeMessage.c_str(), welcomeMessage.length(), 0);
    char receiveBuffer[201] = "";
    recv(clientSocket, receiveBuffer, 200, 0);
    std::cout << "Zadaj tvoju odpoved " << clientName << ": " << receiveBuffer << std::endl;
    if (strcmp(receiveBuffer, "1") == 0) {
        return true;
    }

    if (strcmp(receiveBuffer, "2") == 0) {
        sendPreviousGameResultsToClient(clientSocket);
        WelcomeNewClient(clientName, clientSocket);
    }

    return false;
}

void Server::writeGameResultToFile(const std::string& clientName, int score) {
    std::ofstream file;
    std::string filename = "gameResults.txt";

    std::lock_guard<std::mutex> lock(fileMutex); // Ensures synchronized access

    file.open(filename, std::ios::out | std::ios::app);
    if (file.is_open()) {
        std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        file << "Hrac: " << clientName << ", Body: " << score << ", Datum a cas: " << std::ctime(&currentTime) << std::endl;
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void Server::handleClient(int clientSocket) {
    std::string clientName = GetClientName(clientSocket);
    std::cout << "Novo pripojeny klient ma meno: " << clientName << std::endl;

    if (!WelcomeNewClient(clientName, clientSocket)) {
        std::cout << "Klient " << clientName << " sa odpojil..." << std::endl;
        close(clientSocket);
        return;
    }

    int pocetSpravnych = 0;

    for (int i = 1; i < 11; ++i) {
        Question otazka = questionManager.getRandomQuestion();
        std::string bufferQuestion = "\n\n" + std::to_string(i) + ". otazka znie:\n" + otazka.getQuestion();

        for (const std::string& option : otazka.getOptions()) {
            bufferQuestion += "\n" + option;
        }

        send(clientSocket, bufferQuestion.c_str(), bufferQuestion.size(), 0);

        // casovac
        bool isAnswered = false;
        bool timeExpired = false;
        auto timerThread = std::thread([&]() {
            {
                std::unique_lock<std::mutex> lock(timerMutex);
                timerCV.wait_for(lock, std::chrono::seconds(120), [&] { return isAnswered || timeExpired; });
            }

            if (!isAnswered) {
                std::cout << "Cas vyprsal, hrac je AFK." << std::endl;
                close(clientSocket);
            }
        });

        char answerQ[200] = "";
        recv(clientSocket, answerQ, 200, 0);

        {
            std::lock_guard<std::mutex> lock(timerMutex);
            isAnswered = true;
            timerCV.notify_one();
        }
        timerThread.join();

        char answerQUpper[201];
        strcpy(answerQUpper, answerQ);

        int len = strlen(answerQUpper);
        for (int i = 0; i < len; ++i) {
            answerQUpper[i] = toupper(answerQUpper[i]);
        }

        std::cout << "Odpoved od pouzivatela " << clientName << " je: " << answerQ << " ." << std::endl;

        std::string bufferQuestionResult = "";

        if (strcmp(answerQ, otazka.getCorrectAnswer().c_str()) == 0 || strcmp(answerQUpper, otazka.getCorrectAnswer().c_str()) == 0) {
            pocetSpravnych++;
            bufferQuestionResult = "Odpovedal si spravne.\n Aktualny pocet bodov: " + std::to_string(pocetSpravnych);
        } else {
            bufferQuestionResult = "Odpovedal si nespravne. Spravna odpoved bola: " + otazka.getCorrectAnswer() + "\n Aktualny pocet bodov: " + std::to_string(pocetSpravnych);
        }

        int sendResult = send(clientSocket, bufferQuestionResult.c_str(), bufferQuestionResult.length(), 0);
        if (sendResult == -1) {
            std::cout << "Chyba pri odosielani spravy klientovi" << std::endl;
            break;
        }
    }

    std::string results = "\n\n-------------\nHRA SKONCILA.\n " + clientName + ", ziskal si " + std::to_string(pocetSpravnych) + " bodov.";
    results += "\nTvoj vysledok bol ulozeny.";
    send(clientSocket, results.c_str(), results.length(), 0);

    std::string gameResult = "\n\n-------------\n " + clientName + " ukoncil hru a ziskal " + std::to_string(pocetSpravnych) + " bodov.\n";
    std::cout << gameResult;

    writeGameResultToFile(clientName, pocetSpravnych);

    close(clientSocket);
}

void Server::cleanUp() {
    close(serverSocket);
    // WSACleanup(); // Toto je nutné jen na Windows
}
