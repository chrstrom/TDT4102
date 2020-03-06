#pragma once

#include <iostream>

class Dummy {
    public:
    
    Dummy() { num = new int{0}; }

    int* num;

    Dummy(const Dummy& d) {
        this->num = new int{*d.num};
    }

    Dummy operator=(const Dummy& rhs) {
        this->num = new int{*rhs.num};
        return *this;
    }


    ~Dummy() { delete num; }
};

void dummyTest();

