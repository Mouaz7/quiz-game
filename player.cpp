#include "player.h"

Player::Player(const string& n, int s)
    : name(n), score(s) {
}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::addScore(int pts) {
    score += pts;
}