#include "Person.h"

ostream& operator<< (ostream& os, const Person& person) {
	return os << "\nName: " + person.getName() << '\n' << "Email: " + person.getEmail() << "\n\n";
}

Person::Person(string name, string email, Car* carPtr) : name{ name }, email{ email }, car{ carPtr } {};

string Person::getName() const { return name; }
string Person::getEmail() const { return email; }

void Person::setEmail(string email) { this->email = email; }

bool Person::hasAvailableSeats() const { return( car != nullptr && car->hasFreeSeats() ? true : false ); }



