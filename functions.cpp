#include "functions.h"

void printFlash() {
    string flash(45, '#');
    for (int i = 0; i < 20; ++i) {
        cout << flash << endl;
    }
}

void flashDot(int timeUnit) {
    // Time for a dot is 1 time unit
    printFlash();
    this_thread::sleep_for(chrono::milliseconds(timeUnit));
}

void flashDash(int timeUnit) {
    // Time for a dash is 3 time units
    printFlash();
    this_thread::sleep_for(chrono::milliseconds(timeUnit * 3));
}


// Flashes a letter
void flashLetter(int timeUnit, const vector<vector<int>>& morseCode, char letter) {
    // -97 is to make letters a-z ACSII decimal unit to be 0-25 for the indexes of the morseCode array
    // (ACSII decimal value for 'a' is 97 so subtracting 97 makes the index for 'a' 0)
    int letterIndex = int(letter) - 97;

    system("cls");
    for (int i = 0; i < morseCode.at(letterIndex).size(); ++i) {
        if (morseCode.at(letterIndex).at(i) == 0) {
            flashDot(timeUnit);
        }
        else {
            flashDash(timeUnit);
        }

        // Clearing screen imitates a flashing lights
        system("cls");

        // The space between symbols (dots and dashes) of the same letter is 1 time unit.
        this_thread::sleep_for(chrono::milliseconds(timeUnit));
    }
}


// Flashes a string
void flashString(int timeUnit, const vector<vector<int>>& morseCode, string word) {
    for (int i = 0; i < word.size(); ++i) {

        // If the character is a letter it is printed in flashes
        if (isalpha(word.at(i))) {
            flashLetter(timeUnit, morseCode, word.at(i));
            
            // The space between letters is 3 time units (flash letter ends with 1 time unit, so add 2 * timeUnit)
            this_thread::sleep_for(chrono::milliseconds(timeUnit * 2));
        }

        // Checks for a space, meaning a new word starts
        else if (isspace(word.at(i))) {

            // The space between words is 7 time units (end of letter is 3 time units so add 4)
            this_thread::sleep_for(chrono::milliseconds(timeUnit * 4));
        }
        // Does not check for punctuation or numbers
        // Morse code of punctuation and numbers exists, but I do not want to practice those with this program
        
        // If you want to add punctuation or numbers to this, then you will have to change the morseCode vector of vectors to have those instructions
        // and have to allign the indexes with the ASCII chart decimal values. Also the -97 will have to change to allign with ASCII as well.
    }
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
                << "0.\tExit to Main Menu" << endl << endl;
        cout << "Enter a number 0-3:  ";

        cin >> menuChoice;
        cin.ignore();

        // Validates user input
        while (!cin || menuChoice > 3 || menuChoice < 0) {
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
        

    } while (menuChoice != 0);
}


// Rules for morse code
// The length of a dot is 1 time unit.
// A dash is 3 time units.
// The space between symbols (dots and dashes) of the same letter is 1 time unit.
// The space between letters is 3 time units.
// The space between words is 7 time units.