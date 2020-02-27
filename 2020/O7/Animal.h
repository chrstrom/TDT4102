#pragma once

#include "std_lib_facilities.h"
#include "Graph.h"

using namespace Graph_lib;

class Animal {
public:
    Animal(string name, int age) : name{name}, age{age} {}
    const virtual string toString() const  = 0;

protected:
    string name;
    int age;
};


class Cat : public Animal {
public:
    Cat(string name, int age) : Animal{name, age} {};

    const string toString() const override;
};

class Dog : public Animal {
public:
    Dog(string name, int age) : Animal{name, age} {};

    const string toString() const override;
};



void testAnimal();