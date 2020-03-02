#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
	: Graph_lib::Window(xy, w, h, title),
	headerText{ Point{padX, padY - 20}, "Meetings" },

	btnQuit{ Point{x_max() - btnW, 0}, btnW, btnH, "Quit", cb_quit },
	btnNewMeeting{ Point{newX, newY + btnH * 6}, btnW, btnH, "Add meeting", cb_new_meeting },
	btnNewPerson{ Point{newX, newY + btnH * 3}, btnW, btnH, "Add person", cb_new_person },
	
	inBoxDay{ Point{newX, newY}, txtW, btnH, "Day" },
	inBoxStart{ Point{newX, newY + btnH}, txtW, btnH, "Start time" },
	inBoxEnd{ Point{newX, newY + btnH * 2}, txtW, btnH, "End time" },
	inBoxSubj{ Point{newX, newY + btnH * 4}, txtW, btnH, "Subject" },
	inBoxName{ Point{newX, newY}, txtW, btnH, "Name" },
	inBoxEmail{ Point{newX, newY + btnH}, txtW, btnH, "Email" },
	inBoxCar{ Point{newX, newY + btnH * 2}, txtW, btnH, "Car seats" },

	choiceLocation{ Point{newX, newY + btnH * 3}, txtW, btnH, "Location" },
	choiceLeader{ Point{newX, newY + btnH * 5}, txtW, btnH, "Leader" },

	listMeeting{ Point{padX, newY + btnH * 8}, x_max() - 2 * padX, txtW * 2, "All meetings" },
	listPerson{ Point{padX, newY + btnH * 5}, x_max() - 2 * padX, txtW * 2, "All persons" },

	layoutMenu{ Point{x_max() - btnW, btnH * 2}, btnW, btnH, Menu::vertical, "Layout menu" }
{
	// Common
	attach(btnQuit);
	attach(headerText);

	// New meeting
	attachMeetingWidget(inBoxDay);
	attachMeetingWidget(inBoxStart);
	attachMeetingWidget(inBoxEnd);
	attachMeetingWidget(choiceLocation);
	attachMeetingWidget(inBoxSubj);
	attachMeetingWidget(choiceLeader);
	attachMeetingWidget(btnNewMeeting);

	for (auto c : mapCampusString)
		choiceLocation.add(c.second);

	// Meeting list
	attachMeetingWidget(listMeeting);

	// New person
	attachPersonWidget(inBoxName);
	attachPersonWidget(inBoxEmail);
	attachPersonWidget(inBoxCar);
	attachPersonWidget(btnNewPerson);

	// Person list
	attachPersonWidget(listPerson);

	// Menu
	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Meetings", cb_meetings });
	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Persons", cb_persons });
	attach(layoutMenu);

	// Initial window
    displayMeetings();
	// headerText.set_label("Meetings");
	headerText.set_font_size(headerFontSize);
}

MeetingWindow::~MeetingWindow() {
	for (auto& m : meetings) delete m;

	for (auto& p : persons) delete p;

	for (auto& c : cars) delete c;
}

void MeetingWindow::addMeeting() {
	int day = inBoxDay.get_int();
	int start = inBoxStart.get_int();
	int end = inBoxEnd.get_int();
	
	Campus campus = static_cast<Campus>(choiceLocation.value());
	string subject = inBoxSubj.get_string();
	int leaderId = choiceLeader.value();

	inBoxDay.clear_value();
	inBoxStart.clear_value();
	inBoxEnd.clear_value();
	inBoxSubj.clear_value();
	choiceLeader.clear_value();

	string error = "";
	if(day < 1 || day > 31) {
		error += "Day out of range!\n";
	}

	if(start < 0 || start > 23) {
		error += "Start out of range!\n";
	}

	if(start > end) {
		error += "A meeting cannot start before it ends!\n";
	}
	
	if(subject.empty()) {
		error += "No subject added!\n";
	}

	if(leaderId < 0) {
		error += "Leader ID cannot be negative!\n";
	}

	if(error != "") {
		cerr << error;
		return;
	}

	meetings.push_back(new Meeting{ day, start, end, campus, subject, persons[leaderId] });
	updateMeetingList();
}

void MeetingWindow::addPerson() {
	string name = inBoxName.get_string();
	string email = inBoxEmail.get_string();

	Car* car = nullptr;
	if (inBoxCar.get_int() != 0) {
		car = new Car{ inBoxCar.get_int() };
		cars.push_back(car);
	}

	string error = "";
	if(name.empty()) {
		error += "Name cannot be empty!\n";
	}

	if(email.empty()) {
		error += "Email cannot be empty\n";
	}
	
	inBoxCar.clear_value();
	inBoxName.clear_value();
	inBoxEmail.clear_value();

	if(error != "") {
		cerr << error;
		return;
	}

	persons.push_back(new Person{name, email, car});
	choiceLeader.add(persons.back()->getName());

	updatePersonList();
}

void MeetingWindow::displayMeetings() {
	hideWidgets(widgetPerson);
	headerText.set_label("Meetings");
	for(auto w : widgetMeetings) w->show();
}

void MeetingWindow::displayPersons() {
	hideWidgets(widgetMeetings);
	headerText.set_label("Persons");

	for(auto w : widgetPerson) w->show();
}

void MeetingWindow::hideWidgets(vector<Widget*>& widgets) {
	for(auto w : widgets) w->hide();
}

void MeetingWindow::clearWidgetInput(vector<Widget*>& widgets) {
	for(auto w : widgets) w->clear_value();
}

void MeetingWindow::updateMeetingList() {
	stringstream ss;
	for(auto& m : meetings) {
		ss << *m << '\n';
	}
	listMeeting.put(ss.str());
}

void MeetingWindow::updatePersonList() {
	stringstream ss;
	for(auto& p : persons) {
		ss << *p << '\n';
	}
	listPerson.put(ss.str());
}

void MeetingWindow::attachMeetingWidget(Widget& mw) {
	attach(mw);
	widgetMeetings.push_back(&mw);
}

void MeetingWindow::attachPersonWidget(Widget& pw) {
	attach(pw);
	widgetPerson.push_back(&pw);
}


void MeetingWindow::cb_quit(Address, Address pw){
	reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_new_meeting(Address, Address pw) {
	reference_to<MeetingWindow>(pw).addMeeting();
}

void MeetingWindow::cb_new_person(Address, Address pw) {
	reference_to<MeetingWindow>(pw).addPerson();
}

void MeetingWindow::cb_meetings(Address, Address pw) {
	reference_to<MeetingWindow>(pw).displayMeetings();
}

void MeetingWindow::cb_persons(Address, Address pw) {
	reference_to<MeetingWindow>(pw).displayPersons();
}
