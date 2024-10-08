#ifndef PRINTINGFUNCTIONS_H
#define PRINTINGFUNCTIONS_H

#include <iostream>
#include <cctype>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void printFlash();
void flashDot(int);
void flashDash(int);
void flashLetter(int, const vector<vector<int>>&, char);
void flashString(int, const vector<vector<int>>&, string);
void printWrittenLetter(const vector<vector<int>>&, char);
void printWrittenString(const vector<vector<int>>&, string);

#endif