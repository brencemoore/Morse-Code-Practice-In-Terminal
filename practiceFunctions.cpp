#include "practiceFunctions.h"


void practicePrintedMorse(int timeUnit, const vector<vector<int>>& morseCode) {
    int menuChoice;
    int randomLetterIndex;
    string code;
    string answer;

    do {

        // system("cls");
        cout << "\nSelect a way to practice written morse code." << endl
                << "1.\tPractice Letters" << endl
                << "2.\tPractice Words" << endl 
                << "3.\tPractice Sentences" <<  endl 
                << "4.\tPractice Q-Codes" << endl
                << "0.\tExit to Main Menu" << endl << endl;
        cout << "Enter a number 0-3:  ";

        cin >> menuChoice;
        cin.ignore();

        // Validates user input
        while (!cin || menuChoice > 4 || menuChoice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter a number 0-3:  ";
            cin >> menuChoice;
            cin.ignore();
        }

        if (menuChoice == 1) {
            do {
                srand(time(0));
                randomLetterIndex = (rand() % 26) + 97;  // Gets a random number 97-122 for ASCII conversion to character

                code = char(randomLetterIndex);

                printWrittenLetter(morseCode, code.at(0));

                cout << "\n\nEnter the letter:  ";
                getline(cin, answer);

                if (answer.at(0) == code.at(0)) {
                    cout << "\nCorrect!" << endl;
                }
                else {
                    cout << "\nIncorrect. The answer was " << code.at(0) << "." << endl;
                }

                cout << "\nWould you like to guess another letter?" << endl
                     << "(y / n):  ";
                getline(cin, answer);

            } while (answer == "y" || answer == "Y");
        }
    } while (menuChoice != 0);
}


void practiceFlashingMorse(int timeUnit, const vector<vector<int>>& morseCode) {
    int menuChoice;
    int randomLetterIndex;
    string code;
    string answer;

    do {

        // system("cls");
        cout << "\nSelect a way to practice flashing morse code." << endl
                << "1.\tPractice Letters" << endl
                << "2.\tPractice Words" << endl 
                << "3.\tPractice Sentences" <<  endl 
                << "4.\tPractice Q-Codes" << endl
                << "0.\tExit to Main Menu" << endl << endl;
        cout << "Enter a number 0-3:  ";

        cin >> menuChoice;
        cin.ignore();

        // Validates user input
        while (!cin || menuChoice > 4 || menuChoice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter a number 0-3:  ";
            cin >> menuChoice;
            cin.ignore();
        }

        // User guesses a random letter in flashing morse code
        if (menuChoice == 1) {
            do {
                srand(time(0));
                randomLetterIndex = (rand() % 26) + 97;  // Gets a random number 97-122 for ASCII conversion to character

                code = char(randomLetterIndex);
                
                do {
                    cout << "\nGet ready to guess." << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));

                    flashLetter(timeUnit, morseCode, code.at(0));
                    cout << "Guess or enter nothing to see again:  ";

                    // cin.ignore();
                    getline(cin, answer);

                } while (answer == "");
                
                if (answer.at(0) == code.at(0)) {
                    cout << "\nCorrect!" << endl;
                }
                else {
                    cout << "\nIncorrect. The answer was " << code.at(0) << "." << endl;
                }

                cout << "\nWould you like to guess another letter?" << endl
                     << "(y / n):  ";
                getline(cin, answer);
            } while (answer == "y" || answer == "Y");
        }

        // User guesses a random word in flashing morse code
        if (menuChoice == 2) {
            
        }
        

    } while (menuChoice != 0);
}


// Rules for morse code
// The length of a dot is 1 time unit.
// A dash is 3 time units.
// The space between symbols (dots and dashes) of the same letter is 1 time unit.
// The space between letters is 3 time units.
// The space between words is 7 time units.