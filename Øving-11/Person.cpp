#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.firstname << ' ' << p.lastname << ' ';
}


//THIS IS A TEST COMMENT