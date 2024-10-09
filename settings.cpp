#include "settings.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Settings::Settings() {
    std::fstream file;
    std::vector<std::string> settingList(9);

    file.open("settings.txt", std::ios::in);

    if (!file.is_open()) {
        std::cout << std::endl << "Could not open settings.txt.\nNew settings file created." << std::endl << std::endl;

        timeUnitLength = 150;   // In ms
        printCharacter = '#';
        printWidth = 20;
        printHeight = 45;
        numbers = false;
        punctuation = false;
        qcodes = false;
        wordFile = "words.txt";
        sentenceFile = "sentences.txt";
    }
    else {
        file.close();

        readData(settingList);

        timeUnitLength = stoi(settingList.at(0));
        printCharacter = (settingList.at(1).at(0));
        printWidth = stoi(settingList.at(2));
        printHeight = stoi(settingList.at(3));

        // If statements are used for more consistent conversions from settings file
        if (settingList.at(4) != "1") {
            numbers = false;
        } else {numbers = true;}
        if (settingList.at(5) != "1") {
            punctuation = false;
        } else {punctuation = true;}
        if (settingList.at(6) != "1") {
            qcodes = false;
        } else {qcodes = true;}

        wordFile = settingList.at(7);
        sentenceFile = settingList.at(8);
    }
}

void Settings::readData(std::vector<std::string> &settingList) {
    std::string data;
    std::fstream file;
    int i = 0;
    int colonIndex;
    int dataLength;

    file.open("settings.txt", std::ios::in);
    
    while (getline(file, data)) {
        dataLength = data.length();
        colonIndex = data.find(':');
        data = data.substr(colonIndex + 1, dataLength - colonIndex - 1);
        settingList.at(i) = data;
        i += 1;
    }

    file.close();
}

void Settings::printSettings() {
    std::cout << "\n\nSettings" << std::endl << std::endl << std::endl;

    std::right;
    std::cout << "Flash Settings:" << std::endl << "------------------------------" << std::endl;
    std::cout << "1. " << std::setw(18) << "Time Unit Length: " << timeUnitLength << std::endl;
    std::cout << "2. " << std::setw(18) << "Print Character: " << printCharacter << "\t\t(character used when printing flash)" << std::endl;
    std::cout << "3. " << std::setw(18) << "Print Width: " << printWidth << "\t\t(characters per row when printing flash)" << std::endl;
    std::cout << "4. " << std::setw(18) << "Print Height: " << printHeight << "\t\t(number of rows when printing flash)" << std::endl << std::endl;

    std::cout << "Practice Settings:" << std::endl << "------------------------------" << std::endl;
    std::cout << "5. " << std::setw(18) << "Numbers: ";
    if (numbers == 0) {std::cout << "FALSE";} else {std::cout << "TRUE";}
    std::cout << std::endl;

    std::cout << "6. " << std::setw(18) << "Punctuation: ";
    if (punctuation == 0) {std::cout << "FALSE";} else {std::cout << "TRUE";}
    std::cout << std::endl;

    std::cout << "7. " << std::setw(18) << "Q-Codes: ";
    if (qcodes == 0) {std::cout << "FALSE";} else {std::cout << "TRUE";}
    std::cout << std::endl;

    std::cout << "Random File Settings:" << std::endl << "------------------------------" << std::endl;
    std::cout << "8. " << std::setw(18) << "Words File: " << wordFile << std::endl;
    std::cout << "9. " << std::setw(18) << "Sentences File: " << sentenceFile << std::endl;
}

void Settings::saveSettings() {
    std::ofstream file;
    file.open("settings.txt");

    file << "time_unit_length:" << timeUnitLength << std::endl;
    file << "print_character:" << printCharacter << std::endl;
    file << "print_width:" << printWidth << std::endl;
    file << "print_height:" << printHeight << std::endl;
    file << "numbers:" << numbers << std::endl;
    file << "punctuation:" << punctuation << std::endl;
    file << "qcodes:" << qcodes << std::endl;
    file << "default_word_file:" << wordFile << std::endl;
    file << "default_sentence_file:" << sentenceFile;

    file.close();
}


/*
void loadWords() {

}


void loadWords(std::string) {

}


void loadSentences() {

}


void loadSentences(std::string) {

}

*/
