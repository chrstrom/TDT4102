#include "std_lib_facilities.h"
#include "utilities.h"

//Oppgave 1 
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
}

void swapNumbers(int& a, int& b) {
	b = a + b;

	a = b - a;		//a = (a + b) - a = b
	b = b - a;		//b = (a + b) - b = a
}
//bruker referanser siden vi må "returnere" to verdier fra funksjonen, som uten referanser
// kan bli uønskelig komplisert h.



//Oppgave 2
void randomizeVector(vector<int>& vec, unsigned int n, int min, int max) {
	random_device rand;
	mt19937 random(rand());							//Mersenne Twister PRNG
	uniform_int_distribution<> distr(min, max);		//http://www.cplusplus.com/reference/random/mersenne_twister_engine/

	for (int i = 0; i < n; i++) {
		vec.push_back(distr(random));
	}
}

//Oppgave 3
void sortVector(vector<int>& vec) {
	int i{ 1 };
	int vecLength{ static_cast<int>(vec.size()) };

	while (i < vecLength) {
		int j{ i };
		while (j > 0 && vec[j - 1] > vec[j]) {
			swapNumbers(vec[j - 1], vec[j]);
			j--;
		}
		i++;
	}
}

int medianOfVector(const vector<int>& vec) {
	int vecLength{ static_cast<int>(vec.size()) };
	int median{ 0 };

	if (vecLength % 2 == 0) {				//Partall
		int median1 = vec[vecLength / 2];
		int median2 = vec[(vecLength / 2) - 1];
		median = (median1 + median2) / 2;
	}
	else {									//Oddetall
		median = vec[vecLength / 2];
	}
	return median;
}


//Oppgave 4
string randomizeString(int len, char min, char max) {
	int minInt{ static_cast<int>(toupper(min)) };
	int maxInt{ static_cast<int>(toupper(max)) };
	string randomString;

	random_device rand;
	mt19937 randomInt(rand());
	uniform_int_distribution<> distr(minInt, maxInt);

	for (int i = 0; i < len; i++) {
		char randomChar{ static_cast<char>(distr(randomInt)) };
		randomString += randomChar;
	}
	
	return randomString;
}

//OBS: Endret for bruk i mastermind.cpp
string readInputToString(int maxLen, char min, char max) {										
	string str, strIn;
	cout << "Tast inn " << maxLen << " bokstav(er) mellom " << min << " og " << max << ":\n";

	while (maxLen > 0) {
		getline(cin, strIn);

		if (strIn.size() > 4) {
			cout << "max lengde er 4, prøv igjen!\n";
		} 
		
		//iterer gjennom alle char i str (input), sjekk gyldighet
		for (int idx = 0; idx < strIn.size(); idx++) {
			if (maxLen == 0) { break; }

			char tempChar = strIn[idx];
			if (toupper(tempChar) < toupper(min) || toupper(tempChar) > toupper(max)) {
				cout << tempChar << " er utenfor gyldighetsområdet!\n";
			}
			else if (not isalnum(tempChar)) {
				cout << tempChar << " er ikke alfanumerisk!\n";
			}
			else {
				str += tempChar;
				maxLen--;
			}
		}
	}
	return str;
}

int countChar(string str, char character) {
	int counter{ 0 };
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == character) { counter++; }
	}
	return counter;
}

