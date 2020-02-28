#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Person.h"

ostream& operator<<(ostream& os,  Meeting& m);

void testMeetings() {

	vector<Meeting> mv;
	for(int i = 0; i < 10; i++) {
		Meeting m{12, 1, 4, Campus::Trondheim, "Meeting 1 test.", new Person{"PersonLeader", "Test@Person.com", new Car{4}}};
		for(int i = 0; i < 5; i++) {
			m.addParticipant(new Person{"PersonParticipant " + to_string(i + 1), "@" + to_string(i + 1)});
		}
		mv.push_back(m);
	}
	
	vector<const Person*> fpcd = mv[0].findPotentialCoDriving();

	for(const auto& el : fpcd) {
		cout << el << '\n';
	}

}


int main() {

	testMeetings();

	return 0;
}