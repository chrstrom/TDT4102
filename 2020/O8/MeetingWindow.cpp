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
	attachWidget(inBoxDay, 		 WidgetType::Meeting);
	attachWidget(inBoxStart, 	 WidgetType::Meeting);
	attachWidget(inBoxEnd, 		 WidgetType::Meeting);
	attachWidget(choiceLocation, WidgetType::Meeting);
	attachWidget(inBoxSubj, 	 WidgetType::Meeting);
	attachWidget(choiceLeader, 	 WidgetType::Meeting);
	attachWidget(btnNewMeeting,	 WidgetType::Meeting);

	for (const auto& campus : mapCampusString)
		choiceLocation.add(campus.second);

	attachWidget(listMeeting, WidgetType::Meeting);

	attachWidget(inBoxName, 	WidgetType::Person);
	attachWidget(inBoxEmail, 	WidgetType::Person);
	attachWidget(inBoxCar, 		WidgetType::Person);
	attachWidget(btnNewPerson, 	WidgetType::Person);
	attachWidget(listPerson,	WidgetType::Person);

	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Meetings", cb_meetings });
	layoutMenu.attach(new Button{ Point{0, 0}, 0, 0, "Persons", cb_persons });
	attach(layoutMenu);


    displayWidget(WidgetType::Meeting);

	headerText.set_font_size(headerFontSize);
}

MeetingWindow::~MeetingWindow() {
	for (auto& m : meetings) delete m;

	for (auto& p : persons) delete p;

	for (auto& c : cars) delete c;
}

void MeetingWindow::addMeeting() {
	constexpr int hrMax = 23;
	constexpr int hrMin = 0;
	constexpr int dayMax = 31; 
	constexpr int dayMin = 1;

	int day = inBoxDay.get_int();
	int start = inBoxStart.get_int();
	int end = inBoxEnd.get_int();
	
	Campus campus = static_cast<Campus>(choiceLocation.value());
	string subject = inBoxSubj.get_string();
	int leaderID = choiceLeader.value();

	inBoxDay.clear_value();
	inBoxStart.clear_value();
	inBoxEnd.clear_value();
	inBoxSubj.clear_value();
	choiceLeader.clear_value();

	string error = "";
	if(day < dayMin || day > dayMax) {
		error += "Day out of range!\n";
	}

	if(start < hrMin || start > hrMax) {
		error += "Start out of range!\n";
	}

	if(start > end) {
		error += "A meeting cannot start before it ends!\n";
	}
	
	if(subject.empty()) {
		error += "No subject added!\n";
	}

	if(leaderID < 0) {
		error += "Invalid leader ID!\n";
	}

	if(!error.empty()) {
		cerr << error;
		return;
	}

	meetings.push_back(new Meeting{ day, start, end, campus, subject, persons[leaderID] });
	updateList(WidgetType::Meeting);
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

	if(!error.empty()) {
		cerr << error;
		return;
	}

	persons.push_back(new Person{name, email, car});
	choiceLeader.add(persons.back()->getName());

	updateList(WidgetType::Person);
}

void MeetingWindow::displayWidget(WidgetType type) {
	switch(type) {
		case WidgetType::Meeting:{
			hideWidgets(widgetPerson);
			headerText.set_label("Meetings");
			for(const auto& w : widgetMeetings){
				w->show();
			}
			break;
		}

		case WidgetType::Person: {
			hideWidgets(widgetMeetings);
			headerText.set_label("Persons");
			for(const auto& w : widgetPerson){
				w->show();
			}
			break;
		}

		default:
			cerr << "Invalid WidgetType in MeetingWindow:displayWidget()!\n";
	}
}

void MeetingWindow::hideWidgets(vector<Widget*>& widgets) {
	for(auto w : widgets)
		w->hide();
}

void MeetingWindow::updateList(WidgetType type) {
	stringstream ss;
	switch(type) {
		case WidgetType::Meeting: {
			for(const auto& m : meetings) {
				ss << *m << '\n';
			}
			listMeeting.put(ss.str());
			break;
		}

		case WidgetType::Person: {
			for(const auto& p : persons) {
				ss << *p << '\n';
			}
			listPerson.put(ss.str());
			break;
		}
		default:
			cerr << "Invalid WidgetType in MeetingWindow:updateList()!\n";
	}
}

void MeetingWindow::attachWidget(Widget& w, WidgetType type) {
	switch(type) {
		case WidgetType::Meeting:
			widgetMeetings.push_back(&w);
			break;

		case WidgetType::Person:
			widgetPerson.push_back(&w);
			break;

		default:
			cerr << "Invalid WidgetType in MeetingWindow:attachWidget()!\n";
	}

	attach(w);
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
	reference_to<MeetingWindow>(pw).displayWidget(WidgetType::Meeting);
}

void MeetingWindow::cb_persons(Address, Address pw) {
	reference_to<MeetingWindow>(pw).displayWidget(WidgetType::Person);
}
