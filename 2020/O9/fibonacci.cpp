#include "fibonacci.h"


void fillInFibonacciNumbers(int result[], int length) {
    result[0] = 0;
    result[1] = 1;

    for(int i = 2; i < length; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
}

void printArray(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void createFibonacci() {
    std::cout << "Input length: ";
    int len; std::cin >> len; 

    int* fibBuf = new int[len];

    fillInFibonacciNumbers(fibBuf, len);
    printArray(fibBuf, len);

    delete[] fibBuf;
}