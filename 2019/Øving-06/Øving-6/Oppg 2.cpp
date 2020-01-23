#include "Oppg 2.h"

void countChars(string fileName) {
	constexpr char minChar{ 'a' };
	constexpr char maxChar{ 'z' };

	ifstream ifs{ fileName + ".txt" };
	if (!ifs)
		error("Can't open file ", fileName + ".txt");
	string currentLine;

	while (ifs >> currentLine) {
		for (char ch : currentLine) {
			if (tolower(ch) >= minChar && tolower(ch) <= maxChar) {
				++countCharMap[tolower(ch)];
			}
		}
	}

	for (const auto& x : countCharMap) {
		cout << x.first << ": " << x.second << endl;
	}
}