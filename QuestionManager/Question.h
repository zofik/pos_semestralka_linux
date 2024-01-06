//
// Created by zofia on 6. 1. 2024.
//

#ifndef SERVER_VEDOMOSTNA_HRA_QUESTION_H
#define SERVER_VEDOMOSTNA_HRA_QUESTION_H



#include <string>
#include <vector>

class Question {
private:
    std::string question; // Text otázky
    std::vector<std::string> options; // Možnosti odpovedí
    std::string correctAnswer; // Správna odpoveď

public:
    // Konštruktor
    Question(std::string ques, std::vector<std::string> opts, std::string correctAns);

    // Metóda pre získanie znenia otázky
    std::string getQuestion();

    // Metóda pre získanie možností na odpoved
    std::vector<std::string> getOptions();

    // Metóda pre získanie správnej odpovede
    std::string getCorrectAnswer();
};


#endif //SERVER_VEDOMOSTNA_HRA_QUESTION_H
