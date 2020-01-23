#include "headers/oppg1_2_4.h"

// 1a)
void inputAndPrintInteger() {
	int input; 
	cout << "Skriv inn et tall: ";
	cin >> input; 
	cout << "\nDu skrev: " << input << '\n';
}

// 1b)
int inputInteger() {
	int input;
	cout << "Skriv inn et heltall: ";
	cin >> input; 
	cout << '\n';
	return input;
}

// 1c)
void inputIntegersAndPrintSum() {
	int a = inputInteger();
	int b = inputInteger();
	cout << "Summen av tallene: " << a + b << '\n';
}

// 1d) Bruker inputInteger siden den har returnverdi, så vi kan videre behandle tallene vi taster inn

// 1e)
bool isOdd(int n) {
	return n % 2 != 0;
}

// 1f)

void printHumanReadableTime(int seconds) {
	constexpr int S_IN_H = 3600;
	constexpr int M_IN_H = 60;

	int hr = seconds / S_IN_H;						// Hvor mange timer (3600 sekunder) går opp i seconds?
	int min = (seconds % S_IN_H) / M_IN_H;			// Hvor mange minutter (60 sek) går opp i de resterende sekundene (seconds - 3600*hr)?
	int sec = (seconds % S_IN_H) % M_IN_H;			// De resterende sekundene

	cout << hr << " timer " << min << " minutter og " << sec << " sekunder\n"; 
}

// 2a)
void sumIntegersFor() {
	int n = 0; 
	int sum = 0;

	cout << "Antall: ";
	cin >> n;

	for(int i = 0; i < n; i++) {
		int k;
		cout << "Tast inn tall:";
		cin >> k;
		cout << '\n';
		
		sum += k;
	}
}

// 2b)
void sumIntegersWhile() {
	int n = 0;
	int sum = 0;
	do {
		cout << "Tast inn tall (0 for å avslutte):";
		cin >> n;
		sum += n;
	} while(n != 0);

	cout << "Total sum: " << sum << '\n';
}

// 2c)  a: best med for-loop da man definerer antall interasjoner.
//		b: best med while-loop siden man skal gjøre noe helt til input er noe bestemt

double inputDouble() {
	double n;
	cout << "Skriv inn et desimaltall: ";
	cin >> n; 
	cout << '\n';
	return n;
}

void convertNOKtoEUR(double rate) {

	bool validInput = false;

	cout.setf(ios_base::fixed);
	cout.precision(2);

	while(!validInput) {

		cout << "(NOK) ";
		double NOK = inputDouble();
		double EUR = NOK / rate;
	
		if (NOK < 0) {
			cout << "Vennligst tast inn en positiv verdi.\n";
			validInput = false;
		} else {
			cout <<  "(EUR) " << EUR << '\n';
			validInput = true;
		}
	}
}

// 2f) double bedre for å støtte mer nøyaktig input/output
//		void returntype siden det ikke er oppgitt at vi skal bruke verdien noe sted.


double discriminant(double a, double b, double c) {
	return b*b - 4*a*c;
}

void printRealRoots(double a, double b, double c) {
	double d = discriminant(a, b, c);
	double r1 = 0;
	double r2 = 0;
	if (d > 0) {
		r1 = (-b + sqrt(d)) / 2*a;
		r2 = (-b - sqrt(d)) / 2*a;
		cout << "To reelle røtter:\n"
			 << "r1 = " << r1 << '\n'
			 << "r2 = " << r2 << '\n';
	}
	else if (d == 0) {
		r1 = -b / (2*a); 
		cout << "Én reel rot:\n"
			 << "r1 = " << r1 << '\n';
	}
	else {
		cout << "Ingen reelle løsninger!\n";
	}


}

void solveQuadraticEquations() {
	double a, b, c;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;

	printRealRoots(a, b, c);
}

