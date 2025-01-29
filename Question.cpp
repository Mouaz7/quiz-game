#include "Question.h"

Question::Question(const string& text, int pts)
    : questionText(text), points(pts) {
}

Question::~Question() = default;


int Question::getPoints() const {
    return points;
}

string Question::getText() const {
    return questionText;
}
