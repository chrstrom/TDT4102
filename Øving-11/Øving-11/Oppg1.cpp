#include "Oppg1.h"

void printVectorUsingIterators(const std::vector<std::string>& vec) {
	std::vector<std::string>::const_iterator pos;
	std::vector<std::string>::const_reverse_iterator posR;

	//a)
	std::cout << "Using iterator: \n";
	for (pos = vec.begin(); pos != vec.end(); pos++) {
		std::cout << *pos << " ";
	}
	std::cout << "\n\nUsing reverse iterator: \n";
	//b)
	for (posR = vec.rbegin(); posR != vec.rend(); posR++) {
		std::cout << *posR << " ";
	}
}

//c)
void replaceVector(std::vector<std::string>& vec, std::string old, std::string replacement) {
	std::vector<std::string>::iterator iter;

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		if (*iter == old) {
			iter = vec.insert(iter, replacement);
			iter++;
			iter = vec.erase(iter);
		}
	}
}


void printSetUsingIterators(const std::set<std::string>& set) {
	std::set<std::string>::const_iterator pos;
	std::set<std::string>::const_iterator posR;

}