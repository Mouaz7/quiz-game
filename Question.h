#pragma once
#include <string>
using namespace std;
class Question {
private:
    string questionText;
    int points;

public:
    Question(const string& text, int pts);
    virtual ~Question();

    virtual void displayQuestion() const = 0;
    virtual bool checkAnswer(const string& ans) const = 0;
    int getPoints() const;
    string getText() const;
};
