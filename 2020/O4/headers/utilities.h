#pragma once

#include "std_lib_facilities.h"

#include "tests.h"

// Student: string name, int age, string studyProgram
struct Student {
    string name;
    int age;

    string studyProgram;
};

void printStudent(const Student& s);
string randomizeString(int len, char lower, char upper);
string readInputToString(int len, const char lowerBound, const char upperBound);
int countChar(const string& s, const char c);

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);

int randRange(int min, int max);
void swapNumbers(int& a, int& b);

void printVector(const vector<int>& vec);
void randomizeVector(vector<int>& vec, int n);
void sortVector(vector<int>& vec);
float medianOfVector(const vector<int>& vec);
