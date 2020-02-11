#include "headers/tests.h"

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
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testVectorSorting() {
    vector<int> percentages;
     
    randomizeVector(percentages, 5);
    cout << "Before swapping: ";
    printVector(percentages);

    swapNumbers(percentages[0], percentages[1]);
    cout << "After swapping: ";
    printVector(percentages);
}

void testString() {
    const char maxGrade = 'A';
    const char minGrade = 'F';
    constexpr int maxGradeVal = 5;
    vector<int> gradeCount;

    string s = randomizeString(8, maxGrade, minGrade);

    int sum = 0, tot = 0;
    for(int i = 0; i < abs(maxGrade - minGrade) + 1; i++) {
        gradeCount.push_back(countChar(s, i + maxGrade));

        cout << static_cast<char>(maxGrade + i) << ": " << gradeCount[i] << '\n';
        
        sum += gradeCount[i] * (maxGradeVal - i);
        tot += gradeCount[i];
    }
    float avg = static_cast<float>(sum) / tot;
    cout << "Average: " << avg;
}