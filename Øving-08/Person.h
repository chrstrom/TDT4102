#pragma once
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class Person {
	
public:
	friend ostream& operator<< (ostream& os, const Person& person);
	Person(string name, string email, Car* carPtr = nullptr);

	string getName() const;
	string getEmail() const;
	void setEmail(string email);

	bool hasAvailableSeats() const;

private:
	string name;
	string email;
	Car* car;
};

