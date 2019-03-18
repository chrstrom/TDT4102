#pragma once
#include <string>
#include <iostream>

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

