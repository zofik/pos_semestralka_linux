//
// Created by zofia on 6. 1. 2024.
//

#ifndef SERVER_VEDOMOSTNA_HRA_SERVER_H
#define SERVER_VEDOMOSTNA_HRA_SERVER_H


#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstring>
#include <mutex>
#include <condition_variable>
#include "QuestionManager/QuestionsManager.h"

// Pre Linux
#include <unistd.h>
#include <arpa/inet.h>

class Server {
private:
    int serverSocket, acceptSocket;
    int port;

    // Uchovávanie vytvorených vlákien
    std::vector<std::thread> clientThreads;

    // Otazky
    QuestionsManager questionManager;

    // Mutex pre synchronizáciu prístupu k zdieľanému socketu
    std::mutex socketMutex;

    // Mutex pre zapisovanie do súboru
    std::mutex fileMutex;

    // Pre timer
    std::mutex timerMutex;
    std::condition_variable timerCV;

public:
    // Konštruktor
    Server(int portNum);
    ~Server();

    // Inicializácia serverového socketu
    bool setupServerSocket();

    // Pripojenie k danému portu
    bool bindSocket();

    // Spustenie počúvania na pripojenia klientov
    bool startListening();

    // Prijate nového pripojenia klienta
    bool acceptConnection();

    // Vyčistenie
    void cleanUp();

    // Komunikácia s klientom v samostatnom vlákne
    void handleClient(int clientSocket);

    // Spustenie servera
    bool startServer();

    // Získanie mena klienta pomocou socketu
    std::string GetClientName(int clientSocket);

    // Privítanie nového klienta
    bool WelcomeNewClient(const std::string& clientName, int clientSocket);

    // Odoslanie výsledkov všetkých hier klientovi
    void sendPreviousGameResultsToClient(int clientSocket);

    // Zápis výsledku hry do súboru
    void writeGameResultToFile(const std::string& clientName, int score);
};


#endif //SERVER_VEDOMOSTNA_HRA_SERVER_H
