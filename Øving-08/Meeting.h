#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "Person.h"

using namespace std;

enum class Campus{ Trondheim, Ålesund, Gjøvik};

static map<Campus, string> campusMap{
	{Campus::Trondheim, "Trondheim"},
	{Campus::Gjøvik, "Gjøvik"},
	{Campus::Ålesund, "Ålesund"}
};

class Meeting {
public:
	Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader);
	~Meeting();

	int getDay() const { return day; }
	int getStartTime() const { return startTime;  }
	int getEndTime() const { return endTime; }

	string getLocation() const { return campusMap[location]; }
	string getSubject() const { return subject; }
	const Person* getLeader() { return leader; }

	vector<string> getParticipantList() const;

	void addParticipants(Person* p) { participants.insert(p); }

	vector<const Person*> findPotentialCoDriving();
private:
	int day;
	int startTime;
	int endTime;

	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;

	static set<const Meeting*> meetings;

	bool checkTime(const Meeting* m1, const Meeting* m2);
};


