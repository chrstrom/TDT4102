#pragma once

#include <iostream>
#include <utility>

class Dummy {
    public:
    
    Dummy() { num = new int{0}; }

    int* num;

    Dummy(const Dummy& d) {
        num = new int{*d.num};
    }

    Dummy operator=(Dummy& rhs) {
        std::swap(num, rhs.num);
        return *this;
    }

    ~Dummy() { delete num; }
};

void dummyTest();

