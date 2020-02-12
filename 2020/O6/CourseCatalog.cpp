#include "CourseCatalog.h"

ostream& operator<<(ostream& os, const CourseCatalog& catalog) {
	for(const auto& course : catalog.catalog)
		os << course.first << COURSE_SEP << " " << course.second << '\n';

	return os;
}

void CourseCatalog::saveToFile(const string& filename) const {
	ofstream outFile{filename};

	if(!outFile) {
		cerr << "Couldn't open file: " + filename + '\n';
		return;
	}

	for (const auto& course : catalog)
		outFile << course.first << COURSE_SEP << " " << course.second << '\n';
		
	
}
void CourseCatalog::loadFromFile(const string& filename){
	ifstream inFile{filename};
	
	if(!inFile) {
		cerr << "Couldn't open file: " + filename + '\n';
		return;
	}

	catalog.clear();

	for(string line; getline(inFile, line);) {
		stringstream ss{line};

		string code; getline(ss, code, COURSE_SEP);
		string name; getline(ss, name, COURSE_SEP);
	
		catalog[code] = name.substr(1);		// Removes a trailing white space
	}
}
