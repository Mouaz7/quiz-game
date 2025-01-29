#pragma once
#include <vector>
#include <string>
#include "quiz.h"

class QuizHandler {
private:
    vector<Quiz*> quizzes;
    string quizListFile; 

public:
    QuizHandler(const string& quizListFilename);
    ~QuizHandler();

    void loadAllQuizzes();
    void saveQuizList();
    void createQuiz();
    void listQuizzes();
    void playQuiz();
    void showQuizLeaderboard();
};
