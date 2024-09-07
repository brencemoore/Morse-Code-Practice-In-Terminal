#include "functions.h"

void printFlash() {
    string flash(45, '#');
    for (int i = 0; i < 20; ++i) {
        cout << flash << endl;
    }
}

void printDot(int timeUnit) {
    // Time for a dot is 1 time unit
    printFlash();
    this_thread::sleep_for(chrono::milliseconds(timeUnit));
}

void printDash(int timeUnit) {
    // Time for a dash is 3 time units
    printFlash();
    this_thread::sleep_for(chrono::milliseconds(timeUnit * 3));
}

// vector const reference
void printLetter(int timeUnit, const vector<vector<int>>& morseCode, char letter) {
    // -97 is to make letters a-z ACSII decimal unit to be 0-25 for the indexes of the morseCode array
    // (ACSII decimal value for 'a' is 97 so subtracting 97 makes the index for 'a' 0)
    int letterIndex = int(letter) - 97;

    system("cls");
    for (int i = 0; i < morseCode.at(letterIndex).size(); ++i) {
        if (morseCode.at(letterIndex).at(i) == 0) {
            printDot(timeUnit);
        }
        else {
            printDash(timeUnit);
        }

        // Clearing screen imitates a flashing lights
        system("cls");

        // The space between symbols (dots and dashes) of the same letter is 1 time unit.
        this_thread::sleep_for(chrono::milliseconds(timeUnit));
    }
}


void printWord(int timeUnit, string word) {
    for (int i = 0; i < word.size(); ++i) {
        
    }
}


void printSentence(int timeUnit, string sentence) {

}




// Rules for morse code
// The length of a dot is 1 time unit.
// A dash is 3 time units.
// The space between symbols (dots and dashes) of the same letter is 1 time unit.
// The space between letters is 3 time units.
// The space between words is 7 time units.