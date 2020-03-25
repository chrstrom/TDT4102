#include "orderedList.h"

void insertOrdered(std::list<Person>& ls, const Person& p) {
 
    for(auto iter = ls.begin(); iter != ls.end(); iter++) {
        if(p < *iter) {
            ls.insert(iter, p);
            return;
        }
    }

    ls.push_back(p);
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << p.fname << " " << p.lname << '\n';
}

bool Person::operator<(const Person& p) const {
    return this->fname + this->lname < p.fname + p.lname;
}