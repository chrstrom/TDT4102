#include "Animal.h"

const string Cat::toString() {
    return "Cat: " + name + " " + to_string(age);
}

const string Dog::toString() {
    return "Dog: " + name + " " + to_string(age);
}


void testAnimal() {
    Vector_ref<Animal> animals;

    animals.push_back(new Animal{"AN1", 20});
    animals.push_back(new Cat{"CT1", 7});
    animals.push_back(new Dog{"DG1", 4});

    for(const auto& an : animals) {
        cout << an->toString() << '\n';
    }

}