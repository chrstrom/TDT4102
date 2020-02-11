#include "headers/utilities.h"

void printStudent(const Student& s) {
    cout << "Name: " << s.name << ". Age: " << s.age << ". Study program: " << s.studyProgram << '\n';
}

string randomizeString(int len, const char lower, const char upper) {
    string s;
    for(int i = 0; i < len; i++) {
        s.push_back(static_cast<char>(randRange(static_cast<int>(toupper(lower)), static_cast<int>(toupper(upper)))));
    }
    return s;
}

string readInputToString(int len, const char lowerBound, const char upperBound) {
    string s = "";
    bool valid = false;

    while(!valid) {
        cout << "Tast inn " << len << " bokstaver mellom " << lowerBound << " og " << upperBound<< '\n';
        getline(cin, s);
    
        valid = true;           // Assume input valid
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(s.length() != len || !isalpha(c) || toupper(c) < toupper(lowerBound) || toupper(c) > toupper(upperBound)) {
                valid = false;  // Set invalid if one of the input-characters does not conform
                continue;
            }
        }

        if(!valid) {
            cout << "Ugyldig input! Prøv igjen\n";
        }
    } 
    return s;
}

int countChar(const string& s, const char c) {
    int count = 0;
    for(const auto& el : s) {
        if(el == c) { count++; }
    }
    return count;
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// Siden vi endrer på to verdier, er referanser greie å bruke, da vi ellers måtte returnert en container med endringene
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}   

int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printVector(const vector<int>& vec) {
     for(const auto& el : vec) {
        cout << el << " ";
    }
    cout << '\n';
}

void randomizeVector(vector<int>& vec, int n) {
    for(int i = 0; i < n; i++) {
        vec.push_back(randRange(0, 100));
    }
}

void sortVector(vector<int>& vec) {
   for(int i = 1; i < vec.size(); i++) {
       int j = i;
       while(j > 0 && vec[j-1] > vec[j]) {
           swapNumbers(vec[j], vec[j-1]);
           j--;
       }
   }
}

float medianOfVector(const vector<int>& vec) {
    int len = vec.size();
    return len % 2 != 0 ? vec[len/2] : (vec[len/2] + vec[len/2 - 1])/2.0;
}
