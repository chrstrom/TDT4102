#pragma once
//Barebones version of Dummy was given in the assignment.
//A copy constructor and assignment operator was added.

class Dummy {
public:
	int *num;
	Dummy() {
		num = new int{ 0 };
	}

	Dummy(const Dummy& d) : num{ new int{*d.num} } {}

	Dummy& operator=(const Dummy& d) {
		this->num = new int{ *d.num };
		return *this;
	}

	~Dummy() {
		delete num;
	}
};

void dummyTest();