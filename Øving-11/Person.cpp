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
/*Skriv en funksjon for � sette inn Person-objekter i en std::list i sortert rekkef�lge. Objektene skal v�re sortert basert
p� den alfabetiske rekkef�lgen til personenes navn. Funksjonen kan for eksempel ha prototypen
void insertOrdered(std::list<Person> &l, const Person& p);
Test denne funksjonen ved � opprette en variabel av typen std::list<Person> og sette
inn en rekke Person-objekter i listen ved hjelp av insertOrdered. Lag s� en l�kke i main()
som skriver ut alle objektene i listen til skjermen.
Hint: Strenger kan sammenlignes alfabetisk ved hjelp av operatorene < og >, slik at uttrykket
"ABCD" < "BCDEF" for eksempel er sant.*/