#include "quizHandlar.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include "yesNoQuestions.h"
#include "multpleAnswerQuestion.h"
#include "direktAnswerQuestion.h"

QuizHandler::QuizHandler(const string& quizListFilename)
    : quizListFile(quizListFilename) {
}

QuizHandler::~QuizHandler() {
    for (auto qz : quizzes) {
        delete qz;
    }
}

void QuizHandler::loadAllQuizzes() {
    ifstream in(quizListFile);
    if (!in.is_open()) {
        ofstream createFile(quizListFile);
        return;
    }

    string line;
    while (getline(in, line)) {
        auto pos = line.find(';');
        if (pos != string::npos) {
            string qName = line.substr(0, pos);
            string dataF = line.substr(pos + 1);

            Quiz* newQuiz = new Quiz(qName, dataF);
            newQuiz->loadFromFile();      // load questions
            newQuiz->loadLeaderboard();   // load scoreboard
            quizzes.push_back(newQuiz);
        }
    }
}

void QuizHandler::saveQuizList() {
    ofstream out(quizListFile);
    if (!out.is_open()) {
        cerr << "Could not write to quiz list file.\n";
        return;
    }
    for (auto qz : quizzes) {
        out << qz->getName() << ";" << qz->getDataFile() << "\n";
    }
}

void QuizHandler::createQuiz() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter name for new quiz: ";
    string quizName;
    getline(cin, quizName);

    string dataFile = quizName + "_quiz_data.txt";

    Quiz* newQuiz = new Quiz(quizName, dataFile);

    cout << "How many questions would you like to add? ";
    int numQ;
    cin >> numQ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numQ; i++) {
        cout << "\nCreate a question " << (i + 1) << "...\n"
            << "Chose type of question (1=Yes/No, 2=MultipleChoice, 3=DirectAnswer): ";
        int t;
        cin >> t;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter question text: ";
        string qtext;
        getline(cin, qtext);

        if (t == 1) {
            // YesNo
            cout << "Is the correct answer 'yes'? (y/n): ";
            string yn;
            getline(cin, yn);
            bool correct = (yn == "y" || yn == "yes");
            newQuiz->addQuestion(new YesNoQuestion(qtext, correct));
        }
        else if (t == 2) {
            // MultipleChoice
            cout << "How many options? (max 4)";
            int nOpts;
            cin >> nOpts;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            vector<string> opts;
            opts.reserve(nOpts);
            for (int j = 0; j < nOpts; j++) {
                cout << "Alternative " << (j + 1) << ": ";
                string optStr;
                getline(cin, optStr);
                opts.push_back(optStr);
            }
            cout << "Which option is correct? (specify exact text): ";
            string corr;
            getline(cin, corr);

            newQuiz->addQuestion(new MultipleChoiceQuestion(qtext, opts, corr));
        }
        else {
            // DirectAnswer
            cout << "What is the correct answer? (text)? ";
            string corr;
            getline(cin, corr);
            newQuiz->addQuestion(new DirectAnswerQuestion(qtext, corr));
        }
    }

    // Save quiz to file
    newQuiz->saveToFile();
    // Load (or init) scoreboard
    newQuiz->loadLeaderboard();

    quizzes.push_back(newQuiz);
    saveQuizList();

    cout << "\nQuiz \"" << quizName << "\" Created!\n";
}

void QuizHandler::listQuizzes() {
    if (quizzes.empty()) {
        cout << "\nNo quizzes available yet.\n";
        return;
    }
    cout << "\navailable quiz:\n";
    for (size_t i = 0; i < quizzes.size(); i++) {
        cout << (i + 1) << ") " << quizzes[i]->getName() << "\n";
    }
}

void QuizHandler::playQuiz() {
    if (quizzes.empty()) {
        cout << "\nNo quizzes available.\n";
        return;
    }
    listQuizzes();
    cout << "Select quiz (number): ";
    int idx;
    cin >> idx;

    if (idx < 1 || idx >(int)quizzes.size()) {
        cout << "Invalid selection.\n";
        return;
    }
    Quiz* chosen = quizzes[idx - 1];

    cout << "Enter the player's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string playerName;
    getline(cin, playerName);

    int sc = chosen->play(playerName);
    cout << "\nPlayers \"" << playerName << "\" got "
        << sc << " points in \"" << chosen->getName() << "\"!\n";
}

void QuizHandler::showQuizLeaderboard() {
    if (quizzes.empty()) {
        cout << "\nNo quizzes available.\n";
        return;
    }
    listQuizzes();
    cout << "Select quiz (number): ";
    int idx;
    cin >> idx;
    if (idx < 1 || idx >(int)quizzes.size()) {
        cout << "Invalid selection.\n";
        return;
    }
    Quiz* chosen = quizzes[idx - 1];
    chosen->showLeaderboard();
}
