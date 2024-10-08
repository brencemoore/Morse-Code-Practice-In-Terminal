#include "settings.h"
#include <iostream>
#include <fstream>

Settings::Settings() {
    std::fstream file;
    std::vector<std::string> settingList(7);

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
    }
    else {
        file.close();

        readData(settingList);

        timeUnitLength = stoi(settingList.at(0));
        printCharacter = (settingList.at(1).at(0));
        printWidth = stoi(settingList.at(2));
        printHeight = stoi(settingList.at(3));
        numbers = stoi(settingList.at(4));
        punctuation = stoi(settingList.at(5));
        qcodes = stoi(settingList.at(6));
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
    std::cout << timeUnitLength << std::endl
                << printCharacter << std::endl
                << printWidth << std::endl
                << printHeight << std::endl 
                << numbers << std::endl 
                << punctuation << std::endl 
                << qcodes << std::endl;
}

/*
void saveSettings() {
    std::fstream file;
    file.open("settings.txt", std::ios::trunc);

    file << ""
}


void loadWords() {

}


void loadWords(std::string) {

}


void loadSentences() {

}


void loadSentences(std::string) {

}

*/
