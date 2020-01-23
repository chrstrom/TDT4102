#include "std_lib_facilities.h"

#include "headers/oppg1_2_4.h"
#include "headers/oppg5.h"
#include "headers/oppg6.h"

int main() {

	int choice = -1;
	while( choice != 0) {
		cout << "\n\nVelg funksjon:\n"
			 << "0) Avslutt\n"
			 << "1) Summer to tall\n"
			 << "2) Summer flere tall\n"
			 << "3) Konverter NOK til EUR\n"
			 << "4) Løs QEs\n"
			 << "5) pythagoras\n"
			 << "6) differenceSeriesAnnuity()\n"
			 << "Angi valg (0-6): ";
		cin >> choice;


		switch(choice) {
			case 0:	// Exit
				break;

			case 1:
				inputIntegersAndPrintSum();
				break;

			case 2:
				sumIntegersWhile();
				break;

			case 3:
				convertNOKtoEUR(11.2);
				break;
			
			case 4:
				solveQuadraticEquations();
				break;

			case 5:
				pythagoras();
				break;

			case 6:
				differenceSeriesAnnuity(10000, 3, 10);
				break;

			default:
				cout << "Ugyldig valg, prøv igjen.\n";
		}
	}
	
	return 0;
}