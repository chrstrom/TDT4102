#pragma once
#include "std_lib_facilities.h"


class CourseCatalog {
public:
	friend ostream& operator<< (ostream&, const CourseCatalog&);

	void addCourse(string courseCode, string courseName);
	void removeCourse(string courseCode);
	string getCourse(string courseCode);

	void loadData(string fileName);
	void saveData(string fileName);

private:
	map<string, string> courseMap;
};

void test(CourseCatalog& catalog);