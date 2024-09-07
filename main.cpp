#include "functions.h"

int main() {

    string answer;
    string menuChoice;
    string flash('#', 20);
    int timeUnit = 100;

    // Each subvector is a series of 0s and 1s where 0 is a dot and 1 is a dash
    const vector<vector<int>> morseCode {
        // a          b             c           d       e         f           g            h          i          j
        {0, 1}, {1, 0, 0, 0}, {1, 0, 1, 0}, {1, 0, 0}, {0}, {0, 0, 1, 0}, {1, 1, 0}, {0, 0, 0, 0}, {0, 0}, {0, 1, 1, 1},
        //  k            l          m       n        o            p             q           r          s       t       u
        {1, 0, 1}, {0, 1, 0, 0}, {1, 1}, {1, 0}, {1, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1}, {0, 1, 0}, {0, 0, 0}, {1}, {0, 0, 1},
        //    v           w            x             y             z
        {0, 0, 0, 1}, {0, 1, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}
    };


    // do {
    //     system("cls");  // For menu formating

    //     cout << "\n\nMorse Code Practice" << endl << endl;
    //     cout << "\nSelect a way to practice morse code below." << endl
    //          << "1.\tPractice written" << endl
    //          << "2.\tPractice lights" << endl
    //          << "3.\tMorse code guide" << endl
    //          << "4.\tSettings" << endl
    //          << "0.\tQuit" << endl << endl;
    //     cout << "Enter a number 0-4:  ";

    //     cin >> menuChoice;


    // } while (menuChoice != "0");

    do {
        flashLetter(timeUnit, morseCode, 'f');
        cout << "again?:  ";
        getline(cin, answer);

    } while (answer == "");
    
    return 0;
}