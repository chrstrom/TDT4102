#pragma once

//Oppgave 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& a, int& b);

//Oppgave 2
void randomizeVector(vector<int>& vec, unsigned int n, int min, int max);

//Oppgave 3
void sortVector(vector<int>& vec);
int medianOfVector(const vector<int>& vec);

//Oppgave 4
string randomizeString(int len, char min, char max);
string readInputToString(int maxLen, char min, char max);
int countChar(string str, char character);
