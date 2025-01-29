#pragma once
#include "Question.h"
#include <string>

class YesNoQuestion : public Question {
private:
    bool correctYes; 

public:
    YesNoQuestion(const string& text, bool correctIsYes);

    void displayQuestion() const override;
    bool checkAnswer(const string& ans) const override;

    static YesNoQuestion* fromFileLine(const string& line);
    string toFileLine() const;
};
