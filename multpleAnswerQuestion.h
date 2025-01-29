#pragma once
#include "Question.h"
#include <vector>
#include <string>

class MultipleChoiceQuestion : public Question {
private:
    vector<string> options;
    string correctOption;

public:
    MultipleChoiceQuestion(const string& text,
        const vector<string>& opts,
        const string& corr);

    void displayQuestion() const override;
    bool checkAnswer(const string& ans) const override;

    static MultipleChoiceQuestion* fromFileLine(const string& line);
    string toFileLine() const;
};
