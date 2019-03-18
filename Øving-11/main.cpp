#include "Oppg1.h"
#include "Person.h"

int main() {

	//Oppgave 1
	std::vector<std::string> vec;
	vec.push_back("Lorem"); vec.push_back("Ipsum"); vec.push_back("Dolor");

	std::set<std::string> s;
	s.insert("Lorem"); s.insert("Ipsum"); s.insert("Dolor");

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


	//Oppgave 2
	std::cout << "\n\nOppgave 2:\n";
	std::list<Person> personList;
	Person A{ "Bjarne", "Stroustrup" }; insertOrdered(personList, A);
	Person B{ "Lasse", "Stroustrup" }; insertOrdered(personList, B);
	Person C{ "Bjarne", "Gloustrup" }; insertOrdered(personList, C);
	Person D{ "Nasse", "Latvig" }; insertOrdered(personList, D);
	Person E{ "Masse", "Ratvig" }; insertOrdered(personList, E);

	for (const auto& p : personList) {
		std::cout << p << '\n';
	}

	std::cout << "\n\n\nPress enter to exit...";
	std::cin.get();		//Stop window from closing right away
	return 0;
}