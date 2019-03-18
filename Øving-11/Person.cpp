#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.firstname << ' ' << p.lastname << ' ';
}

void insertOrdered(std::list<Person>& lst, const Person& p) {
	std::list<Person>::const_iterator iter;
	if (lst.empty()) {
		lst.push_back(p);
		return;
	}
	else {
		for (iter = lst.begin(); iter != lst.end(); iter++) {
			if ((*iter).getName() > p.getName()) {
				lst.insert(iter, p);
				return;
			}
		}
		lst.push_back(p);
	}
}
/*Skriv en funksjon for å sette inn Person-objekter i en std::list i sortert rekkefølge. Objektene skal være sortert basert
på den alfabetiske rekkefølgen til personenes navn. Funksjonen kan for eksempel ha prototypen
void insertOrdered(std::list<Person> &l, const Person& p);
Test denne funksjonen ved å opprette en variabel av typen std::list<Person> og sette
inn en rekke Person-objekter i listen ved hjelp av insertOrdered. Lag så en løkke i main()
som skriver ut alle objektene i listen til skjermen.
Hint: Strenger kan sammenlignes alfabetisk ved hjelp av operatorene < og >, slik at uttrykket
"ABCD" < "BCDEF" for eksempel er sant.*/