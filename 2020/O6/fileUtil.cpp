#include "fileUtil.h"

void writeUserInputToFile(string filename) {

	ofstream outFile{filename};
	if(!outFile) {
		cerr << "Couldn't open file: " + filename + '\n';
		return;
	}

	cout << "Write words to file, ENTER to add word, 'quit' to end:\n";

	for (string word; cin >> word && word != "quit";)
		outFile << word << '\n';
}

void addLineNum(string filename) {
	ifstream inFile{filename};
	ofstream outFile{filename + ".ln"};

	if(!inFile) {
		cerr << "Couldn't open file: " << filename << '\n';
		return;
	}

	if(!outFile) {
		cerr << "Couldn't open file: " << filename << ".ln\n";
		return;
	}

	int ln = 1;
	for(string line; getline(inFile, line); ln++)
		outFile << ln << " " << line << '\n';
}


void charStats(string filename) {
	const char lowerChar = 'a';
	const char upperChar = 'z';

	ifstream inFile{filename};
	if(!inFile) {
		cerr << "Couldn't open file: " << filename << '\n';
		return;
	}

	// Count occurences of each char between upper and lower char
	vector<int> charCounts(upperChar - lowerChar + 1);
	for(unsigned char c; inFile >> c;) {
		if(isalpha(c)) {
			charCounts[tolower(c) - lowerChar]++;
		}
	}

	// Display statistics
	for(char c = lowerChar; c <= upperChar; c++) {
		cout << c << ": " << charCounts[c - lowerChar] << '\n';
	}
}
