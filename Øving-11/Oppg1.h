#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <set>

void printVectorUsingIterators(const std::vector<std::string>& vec);
void replaceVector(std::vector<std::string>& vec, std::string old, std::string replacement);

void printSetUsingIterators(const std::set<std::string>& set);
void replaceSet(std::set<std::string>& s, std::string old, std::string replacement);