#pragma once
#include <string>
#include <vector>
#include "leaderboard.h"
#include "Question.h"

class Quiz {
private:
    string name;    
    string dataFile;  
    Leaderboard leaderboard;
    vector<Question*> questions;

public:
    Quiz(const string& quizName, const string& dataFilename);
    ~Quiz();

    string getName() const;
    string getDataFile() const;

    // load/save questions from/to dataFile
    void loadFromFile();
    void saveToFile();

    void loadLeaderboard();
    void saveLeaderboard();

    void addQuestion(Question* q);

    int play(const string& playerName);
    void showLeaderboard();
};


