#include "quiz.h"
#include "yesNoQuestions.h"
#include "multpleAnswerQuestion.h"
#include "direktAnswerQuestion.h"
#include <fstream>
#include <iostream>
#include <limits>

Quiz::Quiz(const string& quizName, const string& dataFilename)
    : name(quizName), dataFile(dataFilename)
{
}

Quiz::~Quiz() {
    for (auto q : questions) {
        delete q;
    }
}

string Quiz::getName() const {
    return name;
}

string Quiz::getDataFile() const {
    return dataFile;
}

void Quiz::loadFromFile() {
    // clear existing
    for (auto q : questions) {
        delete q;
    }
    questions.clear();

    ifstream in(dataFile);
    if (!in.is_open()) {
        // might not exist yet
        return;
    }
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        // YN, MC, DA
        if (line.find("YN;", 0) == 0) {
            Question* q = YesNoQuestion::fromFileLine(line);
            if (q) questions.push_back(q);
        }
        else if (line.rfind("MC;", 0) == 0) {
            Question* q = MultipleChoiceQuestion::fromFileLine(line);
            if (q) questions.push_back(q);
        }
        else if (line.rfind("DA;", 0) == 0) {
            Question* q = DirectAnswerQuestion::fromFileLine(line);
            if (q) questions.push_back(q);
        }
    }
}

void Quiz::saveToFile() {
    ofstream out(dataFile);
    if (!out.is_open()) {
        cout << "Could not write quiz data to file: " << dataFile << endl;
        return;
    }
    for (auto q : questions) {
        if (auto yn = dynamic_cast<YesNoQuestion*>(q)) {
            out << yn->toFileLine() << endl;
        }
        else if (auto mc = dynamic_cast<MultipleChoiceQuestion*>(q)) {
            out << mc->toFileLine() << "\n";
        }
        else if (auto da = dynamic_cast<DirectAnswerQuestion*>(q)) {
            out << da->toFileLine() << "\n";
        }
    }
}

void Quiz::loadLeaderboard() {
    string lbFile = name + "_leaderboard.txt";
    leaderboard.loadFromFile(lbFile);
}

void Quiz::saveLeaderboard() {
    string lbFile = name + "_leaderboard.txt";
    leaderboard.saveToFile(lbFile);
}

void Quiz::addQuestion(Question* q) {
    questions.push_back(q);
}

int Quiz::play(const string& playerName) {
    // flush leftover input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int totalScore = 0;
    for (auto q : questions) {
        q->displayQuestion();
        string ans;
        getline(cin, ans);
        if (q->checkAnswer(ans)) {
            cout << "correct!\n";
            totalScore += q->getPoints();
        }
        else {
            cout << "wrong!\n";
        }
    }
    leaderboard.addOrUpdate(playerName, totalScore);
    saveLeaderboard();
    return totalScore;
}

void Quiz::showLeaderboard() {
    leaderboard.display();
}
