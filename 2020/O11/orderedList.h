#pragma once

#include <string>
#include <iostream>
#include <list>

class Person {
public:
    Person(std::string f, std::string l) : fname{f}, lname{l} {};
    std::string getFName() const {return fname;};
    std::string getLName() const {return lname;};

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    bool operator<(const Person& p) const;
private:
    std::string fname;
    std::string lname;
};




void insertOrdered(std::list<Person>& ls, const Person& p);