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
};

void loadSettings();
void saveSettings();
void loadWords();
void loadWords(std::string);
void loadSentences();
void loadSentences(std::string);

#endif