#include "iterators.h"


void print_using_iterator() {
    std::vector<std::string> vec {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};

    // auto evaluates to std::vector<std::string>::iterator
    for(auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << '\n';
    }

    for(auto riter = vec.rbegin(); riter != vec.rend(); riter++) {
        std::cout << *riter << '\n';
    }
}

void replace_vec(std::vector<std::string>& vec, std::string old, std::string replacement) {
    std::replace(vec.begin(), vec.end(), old, replacement);
}

void replace_set(std::set<std::string>& s, std::string old, std::string replacement) {
    // std::set does not have std::replace defined for it, so we need to do it manually
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        if(*iter == old) {
            s.erase(iter);
            s.insert(iter, replacement);
        }
    }
}