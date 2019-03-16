#include "Oppg1.h"

void printVectorWithIterators(const std::vector<std::string>& vec) {
	std::vector<std::string>::const_iterator pos;
	std::vector<std::string>::const_reverse_iterator posR;

	//a)
	for (pos = vec.begin(); pos != vec.end(); pos++) {
		std::cout << *pos << " ";
	}
	std::cout << "\n\n";
	//b)
	for (posR = vec.rbegin(); posR != vec.rend(); posR++) {
		std::cout << *posR << " ";
	}
}

//c)
void replace(std::vector<std::string>& vec, std::string old, std::string replacement) {
	std::vector<std::string>::iterator iter;

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		if (*iter == old) {
			//old - > replacement
		}
	}
}