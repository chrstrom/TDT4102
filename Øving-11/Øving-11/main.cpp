#include "LinkedList.h"
#include "Oppg1.h"
#include <iostream>
#include <vector>
#include <string>

int main() {

	//Oppgave 1
	std::vector<std::string> vec;
	vec.push_back("Lorem");
	vec.push_back("Ipsum");
	vec.push_back("Dolor");
	vec.push_back("Sit");
	vec.push_back("Amet");
	vec.push_back("Consectetur");

	//a) og b)
	printVectorWithIterators(vec);

	//c)
	replace(vec, "Ipsum", "Latin");
	printVectorWithIterators(vec);



	std::cin.get();		//Stop window from closing right away
	return 0;
}