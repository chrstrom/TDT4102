#include "Oppg1.h"
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> printVectorWithIterators() {
	std::vector<std::string> vec;
	std::vector<std::string>::const_iterator pos;

	vec.push_back("A");
	vec.push_back("B");
	vec.push_back("C");
	vec.push_back("D");


	for (pos = vec.begin(); pos != vec.end(); pos++) {
		std::cout << *pos;
	}
}