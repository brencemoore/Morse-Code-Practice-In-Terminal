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
void printDot(int);
void printDash(int);
void printLetter(int, const vector<vector<int>>&, char);
void printWord(int, string);
void printSentence(int, string);

#endif