#include "std_lib_facilities.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Norwegian");
	int choice = -1;

	while (choice != 0) {
		cout << "\nVelg funksjon:\n" <<
			"1) Summer to tall\n" <<
			"2) Summer flere tall\n" <<
			"3) Konverter NOK til EURO.\n" <<
			"4) Skriv ut gangetabell.\n" <<
			"5) Finn røtter til andregradsligning.\n" <<
			"6) Serielån og annuitetslån.\n" <<
			"0) Avslutt\n" <<
			"Angi valg(0 - 6) :\n";
		cin >> choice;

		switch (choice) {
		case 0:
			break;
		case 1:
			inputIntegersAndPrintSum();
			break;
		case 2:
			inputIntegersUsingLoopAndPrintSum();
			break;
		case 3:
			convertNOKtoEURO();
			break;
		case 4:
			printMultiplicationTable();
			break;
		case 5:
			solveQuadraticEquation();
			break;
		case 6:
			printLoans();
			break;
		default:
			cout << "Velg et gyldig alternativ.\n";
		}
	}
	return 0;
}
