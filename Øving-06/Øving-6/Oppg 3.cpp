#include "Oppg 3.h"

ostream& operator<< (ostream& os, const CourseCatalog& c) {
	for (const auto& x : c.courseMap) {
		cout << x.first << " " << x.second << endl;
	}
	return os;
}

void CourseCatalog::addCourse(string courseCode, string courseName) {
	courseMap[courseCode] = courseName;
	//courseMap.insert({ courseCode, courseName });
}

void CourseCatalog::removeCourse(string courseCode) {
	courseMap.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode) {
	return courseMap[courseCode];
}

void test(CourseCatalog& catalog) {

	catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	catalog.addCourse("TDT4102", "Prosedyre - og objektorientert programmering");
	catalog.addCourse("TMA4100", "Matematikk 1");
	//cout << catalog << "\n\n";

	//catalog.addCourse("TDT4102", "C++");
	//cout << catalog << "\n\n";
	//operator[] = ny entry eller oppdater allerede-eksisterende
	//insert() = ny entry, ikke oppdater allerede-eksisterende
}
void CourseCatalog::loadData(string fileName) {
	string line;
	constexpr int keyLen{ 7 };

	ifstream ifs{ fileName + ".txt" };
	if (!ifs)
		error("Error opening file ", fileName);

	while (getline(ifs, line)) {
		string key{ line.substr(0, keyLen) };
		string name{ line.substr(keyLen, line.length()) };
		courseMap[key] = name;
	}

	//Alternativt: les key frem til første mellomrom, resten er navnet
}
void CourseCatalog::saveData(string fileName) {
	ofstream ofs{ fileName + ".txt" };
	if (!ofs)
		error("Error opening file ", fileName);

	for (const auto& x : courseMap) {
		ofs << x.first << " " << x.second << endl;
	}
}

