#include "yesNoQuestions.h"
#include <iostream>
#include <algorithm> // for transform

YesNoQuestion::YesNoQuestion(const string& text, bool correctIsYes)
    : Question(text, 5), correctYes(correctIsYes)
{
}

void YesNoQuestion::displayQuestion() const {
    cout << this->getText() << " (yes/no)? ";
}

bool YesNoQuestion::checkAnswer(const string& ans) const {
    string lower = ans;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    bool userSaidYes = (lower == "yes" || lower == "y");
    return (userSaidYes == correctYes);
}

// Format: "YN;Is the sky blue?;yes"
YesNoQuestion* YesNoQuestion::fromFileLine(const string& line) {
    // Split on ';'
    // 0: "YN"
    // 1: "Is the sky blue?"
    // 2: "yes"
    size_t first = line.find(';');
    size_t second = line.find(';', first + 1);
    if (first == string::npos || second == string::npos) {
        return nullptr;
    }
    string text = line.substr(first + 1, second - (first + 1));
    string yesno = line.substr(second + 1);
    bool correct = (yesno == "yes");

    return new YesNoQuestion(text, correct);
}

string YesNoQuestion::toFileLine() const {
    // e.g. "YN;Is the sky blue?;yes"
    string yesno = (correctYes ? "yes" : "no");
    return "YN;" + this->getText() + ";" + yesno;
}
