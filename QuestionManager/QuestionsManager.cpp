//
// Created by zofia on 6. 1. 2024.


#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include "QuestionsManager.h"
#include "Question.h"

bool QuestionsManager::loadQuestionsFromFile() {
    std::ifstream file("otazky.txt");

    if (!std::filesystem::exists("otazky.txt")) {
        std::cout << "Subor s otazkami neexistuje." << std::endl;
        return false;
    }

    if (!file.is_open()) {
        std::cout << "Subor s otazkami sa nepodarilo otvorit." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::string question, option, correctAnswer;

        // Rozdelíme riadok podľa oddelovačov '|' a načítame otázku, možnosti a správnu odpoveď
        std::getline(iss, question, '|');
        std::vector<std::string> options;
        while (std::getline(iss, option, '|')) {
            options.push_back(option);
        }
        correctAnswer = options.back(); // Posledná možnosť je správna odpoveď
        options.pop_back(); // Odstránime správnu odpoveď zo zoznamu možností

        // Tu by si mohol vytvoriť objekt triedy QuizQuestion a uložiť ho do questions
        Question newQuestion(question, options, correctAnswer);
        questions.push_back(newQuestion);

    }

    file.close();
    // std::cout << "Pocet nacitanych otazok: " << questions.size() << std::endl; // Kontrolný výpis
    return true;
}

Question QuestionsManager::getRandomQuestion() const {
    // Inicializácia generátora náhodných čísel
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, questions.size() - 1);

    // Vyberieme náhodnú otázku
    auto it = std::next(questions.begin(), dis(gen));
    return *it;
}


std::list<Question> QuestionsManager::getQuestions() const {
    return questions;
}

