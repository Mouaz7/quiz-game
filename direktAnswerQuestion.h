#pragma once
#include "Question.h"
#include <string>

class DirectAnswerQuestion : public Question {
private:
    string correctAnswer;

public:
    DirectAnswerQuestion(const string& text, const string& corr);

    void displayQuestion() const override;
    bool checkAnswer(const string& ans) const override;

    static DirectAnswerQuestion* fromFileLine(const string& line);
    string toFileLine() const;
};
