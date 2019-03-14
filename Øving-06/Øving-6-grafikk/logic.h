#pragma once
#include "std_lib_facilities.h"

struct Temps {
	Temps() : max{ 0.0 }, min{ 0.0 } {};

	float max;
	float min;
};

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemps(string filename);
void printTemps(const vector<Temps>& temperature);