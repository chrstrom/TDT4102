#include "Oppg1.h"

int main() {

	//Oppgave 1
	std::vector<std::string> vec;
	vec.push_back("Lorem");
	vec.push_back("Ipsum");
	vec.push_back("Dolor");

	std::set<std::string> s;
	s.insert("Lorem");
	s.insert("Ipsum");
	s.insert("Dolor");

	//a) og b)
	std::cout << "1a), 1b)\n";
	printVectorUsingIterators(vec);

	//c)
	std::cout << "\n\n1c) \n";
	replaceVector(vec, "Lorem", "Latin");
	printVectorUsingIterators(vec);

	//d)
	std::cout << "\n\n1d) \n";
	replaceSet(s, "Lorem", "Latin");
	printSetUsingIterators(s);


	std::cin.get();		//Stop window from closing right away
	return 0;
}