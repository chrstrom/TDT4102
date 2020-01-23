#include "Oppg 1.h"

void inputWordToFile() {
	string outFileName;
	cout << "Enter filename of output file: " << endl;
	cin >> outFileName;

	ofstream ofs{ outFileName + ".txt" };
	if (!ofs) {
		error("Cant open output file!");
	}


	string inputString;
	cout << "Input a string (\"quit\" to end): " << endl;
	while (cin >> inputString) {																							
		cout << "Input a string (\"quit\" to end): " << endl;
		if (inputString == "quit") {
			break;
		}
		else {
			ofs << inputString << '\n';
		}
	}
}

void addNumberCopyFile() {
	string inFileName;
	string outFileName;
	string currentLine;

	cout << "Enter filename of input file: " << endl;
	cin >> inFileName;
	ifstream ifs{ inFileName + ".txt" };

	if (!ifs)
		error("Error opening file ", inFileName);

	cout << "Enter filename of output file: " << endl;
	cin >> outFileName;
	ofstream ofs{ outFileName + ".txt"};

	if (!ofs) 
		error("Error opening file", outFileName);

	int i{ 0 };
	while (ifs >> currentLine) {
		ofs << to_string(i++) << " " << currentLine << endl;
	}
}
