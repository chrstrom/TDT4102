#include "std_lib_facilities.h"


/*Definer en funksjon inputAndPrintInteger som lar brukeren skrive inn et heltall og
skriver det ut til skjerm.*/

void inputAndPrintInteger() {
	int userInput;
	cout << "Input integer: \n";
	cin >> userInput;
	cout << userInput << '\n';
}

/*Definer en funksjon inputInteger som lar brukeren skrive inn et heltall og returnerer
dette. Test funksjonen fra main, slik som dette:*/

int inputInteger() {
	int userInput;
	cout << "Input integer: \n";
	cin >> userInput;

	return userInput;
}

/*Definer en funksjon inputIntegersAndPrintSum som ved å bruke en av funksjonene
du nå har skrevet, leser inn to heltall fra brukeren og skriver ut kun summen til skjermen.*/

void inputIntegersAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();

	cout << x + y << '\n';
}