#include "std_lib_facilities.h"

#include "MeetingWindow.h"
#include "Meeting.h"
#include "Person.h"

ostream& operator<<(ostream& os,  Meeting& m);

void testMeetings() {
	Person p1{"P1", "P1@", new Car{5}};
	Person p2{"P2", "P2@"};
	Person p3{"P3", "P3@", new Car{3}};
	Person p4{"P4", "P4@", new Car{0}};
	Person p5{"P5", "P5@"};

	Meeting m1(1, 8, 10, Campus::Trondheim, "M1", &p1);
	m1.addParticipant(&p2);

	Meeting m2(1, 9, 10, Campus::Trondheim, "M2", &p2);
	m2.addParticipant(&p3);
	m2.addParticipant(&p5);

	Meeting m3(1, 8, 11, Campus::Trondheim, "M3", &p4);
	m3.addParticipant(&p1);
	m3.addParticipant(&p3);
	m3.addParticipant(&p5);

	cout << "All meetings: \n";
	cout << m1  << '\n' << m2 << '\n' << m3 << '\n';

	cout << "Potential co-driving for m3:\n";
	for(const Person* p_person : m3.findPotentialCoDriving()) {
		cout << p_person->getName() << '\n';
	}
}


int main() {

	//testMeetings();

	MeetingWindow mwin{{10, 10}, 900, 600, "MeetingWindow"};
	return gui_main();
}