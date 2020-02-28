#pragma once
#include "std_lib_facilities.h"


class Car {
public:
    Car(int seats) : freeSeats{seats} {};
    bool hasFreeSeat(); 
    void reserveFreeSeat();
    
private:
    int freeSeats;
};


class Person {
public:
    Person(string name, string email, Car* p_car = nullptr);

    friend ostream& operator<<(ostream& os, const Person& p);

    string getName()  const;
    string getEmail() const;

    void setEmail(string email);
    bool hasAvailableSeats() const;

private:
    string name;
    string email;
    Car* p_car;
};
