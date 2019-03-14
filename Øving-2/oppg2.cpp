#include "std_lib_facilities.h"

//A
void inputIntegersUsingLoopAndPrintSum() {
	int sum = 0, input = -1;
	
	cout << "Input number to add to sum, or 0 to exit: \n";
	while (input != 0) {
		cin >> input;
		sum += input;
	}
	cout << "Total sum: " << sum << '\n';
}

//B
/*En for-loop er best der man forhåndsdefinerer antall tall som skal adderes, 
siden en for-loop er grei å bruke der man skal iterere gjennom noe n antall ganger.
En while-løkke er best for det andre alternativet, siden man her ikke vet hvor
mange ganger man skal kjøre gjennom loopen.*/

//C
double inputDouble() {
	double input;
	cout << "Input: \n";
	cin >> input;
	return input;
}

//D
void convertNOKtoEURO() {
	const float rate = 9.8;
	double amtNOK = -1;
	double amtEURO = 0;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);

	while (amtNOK < 0) {
		cout << "Amount in NOK: \n";
		amtNOK = inputDouble();

		if (amtNOK < 0) {
			cout << "Amount must be a positive number.\n";
			continue;
		}
	}
	cout << "In Euro: \n";
	amtEURO = amtNOK * rate;
	
	cout << amtEURO << '\n';
}

//E
/*Bør bruke inputDouble framfor inputInteger siden konverteringen skal fungere for desimaltall, og da vil ikke
inputInteger fungere godt nok, siden den returnerer et heltall. */