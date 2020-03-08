
#include <iostream>

#include "fibonacci.h"
#include "Matrix.h"
#include "Dummy.h"

int main() {
	//createFibonacci();
	Matrix Id{3};
	Matrix Id2{Id};
	Matrix test{2,3 };

	std::cout << Id;
	std::cout << Id2;

	Matrix a = Id;
	
	Matrix b = a + test;
	std::cout << b;
	a  *= 2.3;
	std::cout << a;
	//dummyTest();

	std::cin.get();
	return 0;
}
