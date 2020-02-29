#include "Person.h"

bool Car::hasFreeSeat(){
    return freeSeats;
}

void Car::reserveFreeSeat() {
    freeSeats--;
}


Person::Person(string name, string email, Car* p_car) : name{name}, email{email}, p_car{p_car}{};

ostream& operator<<(ostream& os, const Person& p) {
    return os << p.getName()  << ", "
              << p.getEmail() << ", "
              << (p.p_car ? "Has car " : "No car ")
              << (p.hasAvailableSeats() ? "with seats" : "with no seats") << '\n';
}

string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

void Person::setEmail(string email){
    this->email = email;
}

bool Person::hasAvailableSeats() const {
    return p_car && p_car->hasFreeSeat();
}

