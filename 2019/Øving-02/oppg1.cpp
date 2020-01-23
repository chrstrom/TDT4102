#include "std_lib_facilities.h"

//A
void inputAndPrintInteger() {
	int input;
	cout << "Input integer: \n";
	cin >> input;
	cout << input << '\n';
}

//B
int inputInteger() {
	int input;
	cout << "Input integer: \n";
	cin >> input;

	return input;
}

//C
void inputIntegersAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();

	cout << x + y << '\n';
}

//D
/*Valgte inputInteger() siden den returnerer en verdi, som tillater programmet
å faktisk fungere*/

//E
bool isOdd(int n) {
	if (n % 2 == 0) {
		return false;
	} else {
		return true;
	}
}

//E
void printHumanReadableTime(int s) {
	const int secInHrs = 3600;
	const int minInHrs = 60;
	int hrs; int min; 
	int sec = s;

	hrs = sec / secInHrs;
	min = (sec % secInHrs) / minInHrs;
	sec = (sec % secInHrs) % minInHrs;

	cout << s << " seconds = " 
		<< hrs << " hours, "
		<< min << " minutes, "
		<< sec << " seconds\n";
}