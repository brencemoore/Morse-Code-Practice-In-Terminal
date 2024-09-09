#include "functions.h"

int main() {

    string answer;
    string flash('#', 20);
    int menuChoice;
    int timeUnit = 150;

    // Each subvector is a series of 0s and 1s where 0 is a dot and 1 is a dash
    const vector<vector<int>> morseCode {
        // a          b             c           d       e         f           g            h          i          j
        {0, 1}, {1, 0, 0, 0}, {1, 0, 1, 0}, {1, 0, 0}, {0}, {0, 0, 1, 0}, {1, 1, 0}, {0, 0, 0, 0}, {0, 0}, {0, 1, 1, 1},
        //  k            l          m       n        o            p             q           r          s       t       u
        {1, 0, 1}, {0, 1, 0, 0}, {1, 1}, {1, 0}, {1, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1}, {0, 1, 0}, {0, 0, 0}, {1}, {0, 0, 1},
        //    v           w            x             y             z
        {0, 0, 0, 1}, {0, 1, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}
    };


    do {
        // system("cls");  // For menu formating

        cout << "\n\nMorse Code Practice" << endl << endl;
        cout << "\nSelect a way to practice morse code below." << endl
             << "1.\tPractice written" << endl
             << "2.\tPractice lights" << endl
             << "3.\tMorse code guide" << endl
             << "4.\tSettings" << endl
             << "0.\tQuit" << endl << endl;
        cout << "Enter a number 0-4:  ";

        cin >> menuChoice;

        // Validates user input
        while (!cin || menuChoice > 4 || menuChoice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter a number 0-4:  ";
            cin >> menuChoice;
        }

        // Practice flashing light morse code
        if (menuChoice == 2) {
            practiceFlashingMorse(timeUnit, morseCode);
        }

    } while (menuChoice != 0);




    return 0;

    string code;

    cout << "Enter code: ";
    cin >> code;
    cin.ignore();

    do {
        this_thread::sleep_for(chrono::milliseconds(1500));

        flashString(timeUnit, morseCode, code);
        cout << "again?:  ";
        getline(cin, answer);

    } while (answer == "");\
    
    if (answer == code) {
        cout << "\nCorrect!" << endl;
    }
    else {
        cout << "\nIncorrect." << endl;
    }
    
    return 0;
}