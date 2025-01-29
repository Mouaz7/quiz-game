#include "multpleAnswerQuestion.h"
#include <iostream>
#include <sstream>   

MultipleChoiceQuestion::MultipleChoiceQuestion(const string& text, const vector<string>& opts, const string& corr)
    : Question(text, 5), options(opts), correctOption(corr)
{
}

void MultipleChoiceQuestion::displayQuestion() const {
    cout << this->getText() << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << (i + 1) << ") " << options[i] << "\n";
    }
    cout << "Enter your answer (text or number): ";
}

bool MultipleChoiceQuestion::checkAnswer(const string& ans) const {
    if (ans == correctOption) return true;

    try {
        int idx = stoi(ans) - 1;
        if (idx >= 0 && idx < (int)options.size()) {
            return (options[idx] == correctOption);
        }
    }
    catch (...) {
    }
    return false;
}

// Format: "MC;What is 2+2?;2|3|4|5;4"
MultipleChoiceQuestion* MultipleChoiceQuestion::fromFileLine(const string& line) {
    // Split by ';'
    //  0: "MC"
    //  1: "What is 2+2?"
    //  2: "2|3|4|5"
    //  3: "4"
    stringstream ss(line);
    vector<string> parts;
    {
        string token;
        while (getline(ss, token, ';')) {
            parts.push_back(token);
        }
    }
    if (parts.size() < 4) return nullptr;

    string text = parts[1];
    string optStr = parts[2];
    string corrOpt = parts[3];

    // Split optStr on '|'
    vector<string> opts;
    {
        stringstream sopt(optStr);
        string piece;
        while (getline(sopt, piece, '|')) {
            opts.push_back(piece);
        }
    }

    return new MultipleChoiceQuestion(text, opts, corrOpt);
}

string MultipleChoiceQuestion::toFileLine() const {
    string optStr;
    for (size_t i = 0; i < options.size(); ++i) {
        optStr += options[i];
        if (i + 1 < options.size()) optStr += "|";
    }
    return "MC;" + this->getText() + ";" + optStr + ";" + correctOption;
}
