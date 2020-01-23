#include "oppg1.h"
#include "Matrix.h"
#include "Dummy.h"
#include <iostream>
#include <string>

int main() {
	using std::cout;
	using std::cin;

	//Oppgave 2
	Matrix J{ 2, 2 };
	Matrix K{ 3 };
	Matrix L;

	//Oppgave 4;
	Matrix A{ 2, 2 };
	A.set(0, 0, 1.0); A.set(0, 1, 2.0); A.set(1, 0, 3.0); A.set(1, 1, 4.0);

	Matrix B{ 2 };
	B.set(0, 0, 4.0); B.set(0, 1, 3.0); B.set(1, 0, 2.0); B.set(1, 1, 1.0);

	Matrix C{ 2 };
	C.set(0, 0, 1.0); C.set(0, 1, 3.0); C.set(1, 0, 1.5); C.set(1, 1, 2.0);

	int choice{ -1 };
	while (choice != 0) {
		cout << "Meny:\n"
			<< "1: createFibonacci();\n"
			<< "2: Matrisetest 1\n"
			<< "3: Dummy\n"
			<< "4: Matrisetest 2 (+ og +=)\n"
			<< "0: Quit\n\n"
			<< "Choice: ";

		cin >> choice;
		switch (choice) {
		case 1:
			createFibonacci();
			cout << "\n\n";
			break;
		case 2:
			cout << "\n\nMatrix(int nRow, int nColumns);\n";
			cout << J;
			cout << "\n\nexplicit Matrix(int nRow);\n";
			cout << K;
			cout << "\n\nMatrix();\n\n";
			cout << L;

			break;
		case 3:
			dummyTest();
			cout << "\n\n";
			break;
		case 4:
			A += B + C;

			cout << "A: " << A << "\n\n";
			cout << "B: " << B << "\n\n";
			cout << "C: " << C << "\n\n";
			
			break;
		case 0:
			cout << "Avslutter... \n";
			break;
		default:
			cout << "Invalid choice.\n";
		}
	}


	return 0;
}