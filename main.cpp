#include <iostream>
#include "quizHandlar.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    QuizHandler handler("quizzes.txt");

    handler.loadAllQuizzes();

    while (true) {
        cout << "\n=== HUVUDMENY ===\n"
            << "1) Create a quiz\n"
            << "2) Play a quiz\n"
            << "3) Show leaderboard\n"
            << "4) End\n"
            << "Choice: ";
        int val;
        cin >> val;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (val == 1) {
            handler.createQuiz();
        }
        else if (val == 2) {
            handler.playQuiz();
        }
        else if (val == 3) {
            handler.showQuizLeaderboard();
        }
        else {
            cout << "done...\n";
            break;
        }
    }

    return 0;
}
