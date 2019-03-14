#include "std_lib_facilities.h"

/* Oppgave 1:
	 def isFibbonaciNumber(n):
		a = 0
		b = 0

		while b < n:
			temp = b
			b += a
			a = temp

		return b == n

*/

// Oppgave 2

//a
int maxOfTwo(int a, int b) {
	if (a > b) {
		cout << "A is greater than B\n";
		return a;
	}
	else {
		cout << "B is greater than A\n";
		return b;
	}
}

//c
int fibonacci(int n) {
	int a = 0;
	int b = 1;

	cout << "Fibonacci numbers: \n";

	for (int i = 1; i <= n; ++i) {
		cout << i << ' ' << b << '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}

//d
int squareNumberSum(int n) {
	int totalSum = 0;

	for (int i = 0; i < n; ++i) {
		totalSum += i * i;
		cout << i * i << endl;
	}
	cout << "Total sum:\n";
	return totalSum;
}


//e
void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;

	cout << "Triangle numbers below " << n << ":\n";
	while (acc < n) {
		cout << acc << '\n';
		acc += num;
		num += 1;
	}
	cout << "\n";
}

//f
bool isPrime(int n) {
	for (int j = 2; j < n; ++j) {
		if (n%j == 0) {
			return false;
		}
	}
	return true;
}

//g
void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; ++number) {
		if (isPrime(number)) {
			cout << number << " is prime.\n";
		}
	}
}

//h
int findGreatestDivisor(int n) {
	cout << "Number: " << n << '\n';
	for (int divisor = n - 1; divisor > 0; --divisor) {
		if (n%divisor == 0) {
			cout << "Greatest divisor: ";
			return divisor;
		}
	}
}
