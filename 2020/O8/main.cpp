#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Person.h"

void testMeetings() {

	Meeting m1{12, 1, 4, Campus::Trondheim, "Meeting 1 test.", new Person{"PersonLeader", "Test@Person.com"}};
	for(int i = 0; i < 5; i++) {
		m1.addParticipant(new Person{"PersonParticipant " + to_string(i + 1), "@" + to_string(i + 1)});
	}

	cout << m1;
}


int main() {

	testMeetings();

	return 0;
}