#pragma once

#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

void print_using_iterator();
void replace_vec(std::vector<std::string>& vec, std::string old, std::string replacement);
void replace_set(std::set<std::string>& s,      std::string old, std::string replacement);
