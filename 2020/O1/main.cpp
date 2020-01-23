
#include "std_lib_facilities.h"

/*
1a)

def isFibonacciNumber(n):
	a = 0
	b = 1
	while( b < n):
		temp = b
		b += a
		a = temp
		
	return b == n
*/


// 2a)
int maxOfTwo(int a, int b) {
	cout << (a > b ? "A is greater than B\n" : "B is greater than or equal to A\n");
	return a > b ? a : b; 
}

// 2c)
long long fibonacci(int n) {
	long long a = 0;
	long long b = 1;

	cout << "Fibonacci numbers\n";
	for(int x = 0; x < n+1; x++) {
		cout << x << ' ' << b << '\n';
		long long temp = b;
		b += a;
		a = temp;
	}
	cout << "----";
	return b;
}

// 2d)
long squareNumberSum(int n) {
	long totalSum = 0;
	for(int i = 0; i < n; i++) {
		totalSum += i * i;
		cout << i * i << '\n';
	}
	cout << totalSum;
	return totalSum;
}

// 2e)
void triangleNumbersBelow(int n) {
	int acc = 1; 
	int num = 2;

	cout << "Triangle numbers below " << n << '\n';
	while(acc < n) {
		cout << acc;
		acc += num;
		num += 1;
	}
	cout << "";
}

int main() {
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << '\n';

	fibonacci(100);
	squareNumberSum(100);

	return 0;
}

