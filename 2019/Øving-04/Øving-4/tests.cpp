#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

//Oppgave 1
void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testCallByReference() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testSwapNumbers() {
	int a = 10, b = 7;

	cout << "Before swapping: a = " << a << ", b = " << b << endl;
	swapNumbers(a, b);
	cout << "After swapping: a = " << a << ", b = " << b << endl;
}


//Oppgave 2
void testVectorSorting() {
	vector<int> percentages;
	constexpr int amt = 10;

	randomizeVector(percentages, amt, 0, 100);

	cout << "Percentages: [ ";
	for (unsigned int element : percentages) {
		cout << element << ' ';
	}
	cout << ']' << endl;

	cout << "Percentages swapped1: [ ";
	swapNumbers(percentages[0], percentages[1]);
	for (unsigned int element : percentages) {
		cout << element << ' ';
	}
	cout << ']' << endl;

	cout << "Percentages sorted: [";
	sortVector(percentages);
	for (unsigned int element : percentages) {
		cout << element << ' ';
	}
	cout << ']' << endl;


	cout << "Median: " << medianOfVector(percentages) << endl;
}

//Oppgave 4
void testString() {
	string grades;
	grades = randomizeString(8, 'A', 'F');

	cout << "Grades: ";
	for (int i = 0; i < grades.size(); i++) {
		cout << grades[i] << ' ';
	}

	vector<int> gradeCount;
	int A = countChar(grades, 'A');	gradeCount.push_back(A);
	int B = countChar(grades, 'B'); gradeCount.push_back(B);
	int C = countChar(grades, 'C'); gradeCount.push_back(C);
	int D = countChar(grades, 'D'); gradeCount.push_back(D);
	int E = countChar(grades, 'E'); gradeCount.push_back(E);
	int F = countChar(grades, 'F'); gradeCount.push_back(F);

	double sum{ 0.0 };
	for (int i = 0; i < gradeCount.size(); i++) {
		sum += (5 - i) * gradeCount[i];
	}
	double average = sum / gradeCount.size();

	cout << "Snittkarakter: " << average << endl;
}

//Oppgave 5


