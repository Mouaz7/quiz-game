#pragma once
#include <vector>
#include <string>
#include "player.h"

class Leaderboard {
private:
    vector<Player> players;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;

    void addOrUpdate(const string& playerName, int newPoints);

    void display() const;
};