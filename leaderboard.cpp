#include "leaderboard.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void Leaderboard::loadFromFile(const string& filename) {
    players.clear();
    ifstream in(filename);
    if (!in.is_open()) {
        return;
    }
    string line;
    while (getline(in, line)) {
        auto pos = line.find(',');
        if (pos != string::npos) {
            string pname = line.substr(0, pos);
            int sc = stoi(line.substr(pos + 1));
            players.emplace_back(pname, sc);
        }
    }
}

void Leaderboard::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Could not save leaderboard to file: " << filename << "\n";
        return;
    }
    for (auto& p : players) {
        out << p.getName() << "," << p.getScore() << "\n";
    }
}

void Leaderboard::addOrUpdate(const string& playerName, int newPoints) {
    for (auto& p : players) {
        if (p.getName() == playerName) {
            p.addScore(newPoints);
            return;
        }
    }
    players.emplace_back(playerName, newPoints);
}

void Leaderboard::display() const {
    vector<Player> sorted = players;
    sort(sorted.begin(), sorted.end(),
        [](const Player& a, const Player& b) {
            return a.getScore() > b.getScore();
        });
    cout << "\n--- Leaderboard ---\n";
    int limit = min<int>(5, sorted.size());
    for (int i = 0; i < limit; i++) {
        cout << (i + 1) << ". " << sorted[i].getName()
            << " - " << sorted[i].getScore() << " points\n";
    }
}