#pragma once


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