#include "std_lib_facilities.h"

//B
void printMultiplicationTable() {
	int width, height;
	const char sep = ' ';

	cout << "Width:\n";
	cin >> width;
	cout << "Height:\n";
	cin >> height;
	
	int digits = 0; 
	int heightTemp = height;

	while (heightTemp != 0) { 
		heightTemp /= 10; digits++; 
	}

	int sepWidth = digits + 2;

	for (int i = 1; i <= height; ++i) {
		for (int j = 1; j <= width; ++j) {
			cout << right << setw(sepWidth) << setfill(sep) << j * i;
		}
		cout << '\n';
	}
}
