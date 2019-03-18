#pragma once
#include <string>
#include <iostream>
/*Lag en klasse Person med medlemsvariabler for fornavn og etternavn. 
Inkluder alle konstruktører, medlemsfunksjoner og overlagrede operatorer 
du mener er nyttige, inkludert en måte å skrive ut Person-objekter til skjermen.*/

class Person {
public:
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	Person() : firstname{ "" }, lastname{} {};
	Person(std::string first, std::string last) : firstname{ first }, lastname{ last } {};

	std::string getFirstName() const { return firstname; }
	std::string getLastName() const { return lastname; }
private:
	std::string firstname;
	std::string lastname;
};

