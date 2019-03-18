#include "Oppg1.h"
using std::string;

void printVectorUsingIterators(const std::vector<string>& vec) {
	std::vector<string>::const_iterator pos;
	std::vector<string>::const_reverse_iterator posR;

	//a)
	std::cout << "Using iterator: \n";
	for (pos = vec.begin(); pos != vec.end(); pos++) {
		std::cout << *pos << ' ';
	}
	std::cout << "\n\nUsing reverse iterator: \n";
	//b)
	for (posR = vec.rbegin(); posR != vec.rend(); posR++) {
		std::cout << *posR << ' ';
	}
}

//c)
void replaceVector(std::vector<std::string>& vec, string old, string replacement) {
	std::vector<string>::iterator iter;

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		if (*iter == old) {
			iter = vec.insert(iter, replacement);
			iter++;
			iter = vec.erase(iter);
		}
	}
}

//d)
void printSetUsingIterators(const std::set<string>& set) {
	std::set<string>::const_iterator pos;
	std::set<string>::const_reverse_iterator posR;

	std::cout << "Using iterator: \n";
	for (pos = set.begin(); pos != set.end(); pos++) {
		std::cout << *pos << ' ';
	}
	
	std::cout << "\n\nUsing reverse iterator: \n";
	for (posR = set.rbegin(); posR != set.rend(); posR++) {
		std::cout << *posR << ' ';
	}
}

void replaceSet(std::set<string>& s, string old, string replacement) {
	std::set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		if (*iter == old) {
			iter = s.insert(iter, replacement);
			iter++;
			//iter = s.erase(iter);
			break;
		}
	}
}