#include "Meeting.h"
set<const Meeting*> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader)
	:day{ day }, startTime{ startTime }, endTime{ endTime },
	location{ location }, subject{ subject }, leader{ leader }
{
	addParticipants(leader);
	meetings.insert(this);
}

Meeting::~Meeting() {
	meetings.erase(this);
}

ostream& operator<< (ostream& os, Campus& campus) {
	return os << campusMap[campus] + ' ';
}

ostream& operator<< (ostream& os, Meeting& m) {

	 os << "Subject: "		+ m.getSubject()				+ '\n'
		<< "Location: "		+ m.getLocation()				+ '\n'
		<< "Starting time: "+ to_string(m.getStartTime())	+ '\n' 
		<< "Ending time: "	+ to_string(m.getEndTime())		+ '\n'
		<< "Leader: "		+ m.getLeader()->getName()		+ '\n'

		<< "Participants: ";
	for (const auto& x : m.getParticipantList()) {
		os << x << ", ";
	}
	os << '\n';

	return os;
}

vector<string> Meeting::getParticipantList() const {
	vector<string> participantList;
	for (const auto& person : participants) {
		participantList.push_back(person->getName());
	}
	return participantList;
}


bool Meeting::checkTime(const Meeting* m1, const Meeting* m2) {
	bool overlap{ true };
	int tolerance{ 1 };

	int m1STime{ m1->getStartTime() };
	int m2STime{ m2->getStartTime() };
	int m1ETime{ m1->getEndTime()	};
	int m2ETime{ m2->getEndTime()	};

	//Starting too late
	if (m1STime > m2STime + tolerance || m2STime > m1STime + tolerance) { overlap = false; }
	//Starting too early
	if (m1STime < m2STime - tolerance || m2STime < m1STime - tolerance) { overlap = false; }

	//Ends too late
	if (m1ETime > m2ETime + tolerance || m2ETime > m1ETime + tolerance) { overlap = false; }
	//Ends too early
	if (m1ETime < m2ETime - tolerance || m2ETime < m1ETime - tolerance) { overlap = false; }

	return overlap;
}
vector<const Person*> Meeting::findPotentialCoDriving(){
	vector<const Person*> coDrivers;

	//Values for the Meeting the method is called by
	int thisDay{ this->getDay() };
	string thisLocation{ this->getLocation() };

	//Iterate through all other meetings, add meeting to coDrivers if time, date and location matches
	for (const auto& currentMeeting : meetings) {

		int currentDay{ currentMeeting->getDay() };
		string currentLocation{ currentMeeting->getLocation() };
		bool hasFreeSeats{ currentMeeting->leader->hasAvailableSeats() };

		if (hasFreeSeats && currentLocation == thisLocation
			&& currentDay == thisDay && checkTime(this, currentMeeting)) {
			coDrivers.push_back(currentMeeting->leader);
		}
	}
	return coDrivers;
}
