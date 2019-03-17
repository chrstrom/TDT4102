#include "LinkedList.h"
#include "Oppg1.h"

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
	std::cout << "1a), 1b)\n";
	printVectorUsingIterators(vec);

	//c)
	std::cout << "\n\n1c) \n";
	replaceVector(vec, "Lorem", "Latin");
	printVectorUsingIterators(vec);

	std::cin.get();		//Stop window from closing right away
	return 0;
}