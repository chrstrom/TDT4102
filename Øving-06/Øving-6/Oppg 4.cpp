#include "Oppg 4.h"

istream& operator>>(istream& is, Temps& t) {
	is >> t.max >> t.min;
	return is;
}

vector<Temps> readTemps(const string filename) {
	vector<Temps> temperatures;
	string line;
	Temps t;

	ifstream temps(filename + ".txt");

	while (getline(temps, line)) {
		stringstream ss{ line };
		ss >> t;
		temperatures.push_back(t);
	}
	return temperatures;
}

void printTemps(const vector<Temps>& temperatures) {
	for (auto& t : temperatures) {
		cout << t.max << ' ' << t.min << '\n';
	}
}
