#include "Temps.h"

istream& operator>>(istream& is, Temps& t) {
	return is >> t.max >> t.min;
}

vector<Temps> readTempsFromFile(string filename) {
	ifstream inFile{filename};

	if(!inFile) {
		cerr << "Couldn't open file: " + filename + '\n';
		exit(1);
	}

	vector<Temps> temps;
	for(Temps t; inFile >> t;) {
		temps.push_back(t);
	}	
	
	return temps;
}
