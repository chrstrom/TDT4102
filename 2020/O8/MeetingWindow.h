#pragma once

#include "Window.h"
#include "GUI.h"
#include "Meeting.h"
#include "Person.h"

using namespace Graph_lib;

struct MeetingWindow : Graph_lib::Window {
	static constexpr int btnW = 100; 
	static constexpr int btnH = 20;
	static constexpr int btnMarginY = 4;
	static constexpr int btnOffsetY = btnH + btnMarginY;
	static constexpr int txtW = 200;
	static constexpr int padX = 20;
	static constexpr int padY = 40;
	static constexpr int headerFontSize = 20;
	static constexpr int newY = 30;
	static constexpr int newX = 80;

	MeetingWindow(Point xy, int w, int h, const string& title);
	~MeetingWindow();

private:
	vector<Meeting*> meetings;
	vector<Person*> persons;
	vector<Car*> cars;

	Text headerText;

	Button btnQuit;
	Button btnNewMeeting;
	Button btnNewPerson;

	In_box inBoxDay;
	In_box inBoxStart;
	In_box inBoxEnd;
	In_box inBoxSubj;
	In_box inBoxName;
	In_box inBoxEmail;
	In_box inBoxCar;

	Choice choiceLocation;
	Choice choiceLeader;

	vector<Widget*> widgetMeetings;
	vector<Widget*> widgetPerson;

	Multiline_out_box listMeeting;
	Multiline_out_box listPerson;

	Menu layoutMenu;

	void addMeeting();
	void displayMeetings();

	void addPerson();
	void displayPersons();

	void hideWidgets(vector<Widget*>& widgets);

	void attachMeetingWidget(Widget& mw);
	void attachPersonWidget(Widget& pw);
	void clearWidgetInput(vector<Widget*>& widgets);
	void updateMeetingList();
	void updatePersonList();

	void quit();
	
	static void cb_quit(Address, Address pw);
	static void cb_new_meeting(Address, Address pw);
	static void cb_new_person(Address, Address pw);
	static void cb_meetings(Address, Address pw);
	static void cb_persons(Address, Address pw);
};
