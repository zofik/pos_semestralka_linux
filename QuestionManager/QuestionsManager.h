//
// Created by zofia on 6. 1. 2024.
//

#ifndef SERVER_VEDOMOSTNA_HRA_QUESTIONSMANAGER_H
#define SERVER_VEDOMOSTNA_HRA_QUESTIONSMANAGER_H

#include <vector>
#include <string>
#include <list>
#include "Question.h"

class QuestionsManager {
private:
    std::list<Question> questions; // Zoznam otázok

public:
    // Načítanie otázok zo súboru do premennej questions
    bool loadQuestionsFromFile();

    // Získanie zoznamu otázok
    std::list<Question> getQuestions() const;

    // Získanie náhodnej otázky zo zoznamu
    Question getRandomQuestion() const;
};


#endif //SERVER_VEDOMOSTNA_HRA_QUESTIONSMANAGER_H
