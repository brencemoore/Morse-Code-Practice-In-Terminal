#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cctype>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void printFlash();
void flashDot(int);
void flashDash(int);
void flashLetter(int, const vector<vector<int>>&, char);
void flashString(int, const vector<vector<int>>&, string);

void practicePrintedMorse(int, const vector<vector<int>>&);
void practiceFlashingMorse(int, const vector<vector<int>>&);

#endif