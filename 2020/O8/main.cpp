#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Person.h"

void testMeetings() {

	Meeting m1{12, 1, 4, Campus::Trondheim, "Meeting 1 test.", new Person{"TestPerson", "Test@Person.com"}};
}


int main() {


	return 0;
}