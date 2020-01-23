#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.firstname << ' ' << p.lastname << ' ';
}

void insertOrdered(std::list<Person>& lst, const Person& p) {
	std::list<Person>::const_iterator iter;
	if (lst.empty()) {
		lst.push_back(p);
		return;
	}
	else {
		for (iter = lst.begin(); iter != lst.end(); iter++) {
			if ((*iter).getName() > p.getName()) {
				lst.insert(iter, p);
				return;
			}
		}
		lst.push_back(p);
	}
}
