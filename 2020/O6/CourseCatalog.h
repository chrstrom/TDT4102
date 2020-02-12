#pragma once
#include "std_lib_facilities.h"

constexpr char COURSE_SEP = ':';

class CourseCatalog {
public:
	friend ostream& operator<<(ostream& os, const CourseCatalog& catalog);

	inline void addCourse(const string& key, const string& value);
	inline void removeCourse(const string& key);
	inline string getCourse(const string& key) const;

	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);

private:
	map<string, string> catalog;
};


void CourseCatalog::addCourse(const string& code, const string& name) {
	catalog[code] = name; 
	// Indexing with [] means that we can overwrite entries in the map
	// Using catalog.insert({code, name}, will not overwrite 
}

void CourseCatalog::removeCourse(const string& code) {
	catalog.erase(code);
}

string CourseCatalog::getCourse(const string& code) const {
	return catalog.at(code);
}
