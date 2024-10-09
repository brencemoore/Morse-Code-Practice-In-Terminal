#ifndef SETTING_H
#define SETTING_H

#include <vector>
#include <string>

class Settings {
private:
    int timeUnitLength;
    char printCharacter;
    int printWidth;
    int printHeight;
    bool numbers;
    bool punctuation;
    bool qcodes;
    std::string wordFile;
    std::string sentenceFile;

    void readData(std::vector<std::string>&);

public:
    Settings();
    void printSettings();
    void saveSettings();

    int getTimeUnit() {return timeUnitLength;}
    char getPrintCharacter() {return printCharacter;}
    int getPrintWidth() {return printWidth;}
    int getPrintHeight() {return printHeight;}
    bool getNumbers() {return numbers;}
    bool getPunctuation() {return punctuation;}
    bool getQcodes() {return qcodes;}
    std::string getWordFile() {return wordFile;}
    std::string getSentenceFile() {return sentenceFile;}

    void setTimeUnit(int time) {
        timeUnitLength = time;
    }
    void setPrintCharacter(char character) {
        printCharacter = character;
    }
    void setPrintWidth(int width) {
        printWidth = width;
    }
    void setPrintHeight(int height) {
        printHeight = height;
    }
    void setNumbers(bool active) {
        numbers = active;
    }
    void setPunctuation(bool active) {
        punctuation = active;
    }
    void setQcodes(bool active) {
        qcodes = active;
    }
    void setWordFile(std::string fileName) {
        wordFile = fileName;
    }
    void setSentenceFile(std::string fileName) {
        sentenceFile = fileName;
    }
};

#endif