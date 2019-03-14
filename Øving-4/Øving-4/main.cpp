#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"

int main() {
	setlocale(LC_ALL, "Norwegian");
	
	int choice{ -1 };
	while (choice != 0) {
		cout << "\nMeny: \n" <<
				"1: testCallByValue();\n" 
				"2: testCallByReference();\n"
				"3: testSwapNumbers();\n"
				"4: testVectorSorting();\n"
				"5: testString();\n"
				"6: countChar();\n"
				"7: readInputToString();\n"
				"8: playMastermind();\n"
				"0: Avslutt\n" << endl;
		cin >> choice;
		
		switch (choice) {
		case 1:
			testCallByValue();
			break;
		case 2:
			testCallByReference();
			break;
		case 3:
			testSwapNumbers();
			break;
		case 4:
			testVectorSorting();
			break;
		case 5:
			testString();
			break;
		case 6:
			cout << countChar("KKKKaaabbfqwKdddfsdK", 'K') << endl;
			break;
		case 7:
			cout << readInputToString(4, 'A', 'Z') << endl;
			break;
		case 8:
			playMastermind();
			break;
		case 0:
			cout << "Avslutter..." << endl;
			break;

		default:
			cout << "Tast inn gyldig verdi for valg!" << endl;
		}
	}
	return 0;
}