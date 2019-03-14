#include "myGUI.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title) 
	: Window{ w, h, title }, w{ w }, h{ h }, title{ title }, 
	quitBtn{quitBtnPoint, btnW, btnH, quitBtnTitle, cbQuit},
	personNewBtn{personNewPoint, btnW + 3*personNewTitle.length(), btnH, personNewTitle, cbNewPerson},
	personName{ personNamePoint, fieldW, fieldH, personNameTitle },
	personEmail{ personEmailPoint, fieldW, fieldH, personEmailTitle }
{
	attach(quitBtn);
	attach(personNewBtn);
	attach(personName);
	attach(personEmail);

}

void MeetingWindow::cbQuit(Address, Address pw) { reference_to<MeetingWindow>(pw).hide(); }
void MeetingWindow::cbNewPerson(Address, Address pw) { reference_to<MeetingWindow>(pw).addPerson(); }

void MeetingWindow::addPerson() {;
	string name{ personName.get_string() };
	string email{ personEmail.get_string() };
	if (name != "" && email != "") {
		people.push_back(new Person{ name, email });
	}
}

void MeetingWindow::printPeople() const {
	for (const auto& person : people) { cout << *person; }
}


