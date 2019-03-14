#include "oppg1.h"
#include <iostream>

void fillInFibonacciNumbers(int result[], int length) {
	int x1{ 0 }; result[0] = x1;
	int x2{ 1 }; result[1] = x2;
	int temp{ 0 };
	
	if (length == 1) {
		result[0] = x1;
	}
	else {
		for (int i = 2; i < length; i++) {
			temp = x1 + x2;
			result[i] = temp;
			x1 = x2;
			x2 = temp;
		}
	}
}

void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << ' ';
	}
}

void createFibonacci() {
	int N;
	std::cout << "Input no. of fibonacci numbers: \n";
	std::cin >> N;

	if (N > 0) {
		int* fibArr = new int[N+1];

		fillInFibonacciNumbers(fibArr, N);
		printArray(fibArr, N);
	
	delete[] fibArr;
	}
	else {
		std::cout << "N must be > 0\n\n";
	}
}