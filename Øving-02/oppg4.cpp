#include "std_lib_facilities.h"

//A  (spørsmål: på én linje, eller sånn som det her? NEI)
double discriminant(double a, double b, double c) { 
	return b * b - 4 * a*c;
}

//B
void printRealRoots(double a, double b, double c) {
	double realRoot1;
	double realRoot2;
	double discr = discriminant(a, b, c);

	if (discr < 0) {
		cout << "No real roots.\n";
	} 
	else if (discr == 0) {
		realRoot1 = -b / (2 * a);
		cout << "One real root:\n";
		cout << "x1 = " << realRoot1 << '\n';
	} 
	else {
		realRoot1 = (-b + sqrt(discr)) / 2 * a;
		realRoot2 = (-b - sqrt(discr)) / 2 * a;

		cout << "Two real roots:\n";
		cout << "x1 = " << realRoot1 << " and x2 = " << realRoot2 << '\n';
	} 
}

//C
void solveQuadraticEquation() {
	double a, b, c;
	cout << "ABC-solver:\n";

	cout << "a: \n";
	cin >> a;
	cout << "b: \n";
	cin >> b;
	cout << "c: \n";
	cin >> c;

	printRealRoots(a, b, c);
}