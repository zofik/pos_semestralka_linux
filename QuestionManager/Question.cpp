//
// Created by zofia on 6. 1. 2024.
//

#include "Question.h"

Question::Question(std::string ques, std::vector<std::string> opts, std::string correctAns) {
    question = ques;
    options = opts;
    correctAnswer = correctAns;
}

std::string Question::getQuestion() {
    return question;
}

std::vector<std::string> Question::getOptions() {
    return options;
}

std::string Question::getCorrectAnswer() {
    return correctAnswer;
}

