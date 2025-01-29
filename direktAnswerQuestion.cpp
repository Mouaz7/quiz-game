#include "direktAnswerQuestion.h"
#include <iostream>
#include <algorithm>

DirectAnswerQuestion::DirectAnswerQuestion(const string& text,const string& corr)
    : Question(text, 5), correctAnswer(corr)
{
}

void DirectAnswerQuestion::displayQuestion() const {
    cout << this->getText() << "\nyour answer: ";
}

bool DirectAnswerQuestion::checkAnswer(const string& ans) const {
    string userAns = ans;
    string corr = correctAnswer;

    transform(userAns.begin(), userAns.end(), userAns.begin(), ::tolower);
    transform(corr.begin(), corr.end(), corr.begin(), ::tolower);

    return (userAns == corr);
}

DirectAnswerQuestion* DirectAnswerQuestion::fromFileLine(const string& line) {
    size_t first = line.find(';');
    size_t second = line.find(';', first + 1);
    if (first == string::npos || second == string::npos) return nullptr;

    string text = line.substr(first + 1, second - (first + 1));
    string corr = line.substr(second + 1);

    return new DirectAnswerQuestion(text, corr);
}

string DirectAnswerQuestion::toFileLine() const {
    // "DA;questionText;correctAnswer"
    return "DA;" + this->getText() + ";" + correctAnswer;
}
