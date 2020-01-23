#pragma once
#include <string>
#include <iostream>
#include <list>

//Oppg 2
class Person {

public:
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	Person() : firstname{ "" }, lastname{""} {};
	Person(std::string first, std::string last) : firstname{ first }, lastname{ last } {};

	//std::string getFirstName() const { return firstname; }
	//std::string getLastName() const { return lastname; }
	std::string getName() const { return firstname + " " + lastname; }

private:
	std::string firstname;
	std::string lastname;
};

void insertOrdered(std::list<Person>& lst, const Person& p);