#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
// #include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

void printFlash();
void flashDot(int);
void flashDash(int);
void flashLetter(int, const vector<vector<int>>&, char);
void flashWord(int, string);
void printSentence(int, string);

#endif