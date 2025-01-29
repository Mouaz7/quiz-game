#pragma once
#include <string>

using namespace std;
class Player {
private:
    string name;
    int score;

public:
    Player(const string& n, int s = 0);
    string getName() const;
    int getScore() const;
    void addScore(int pts);
};

