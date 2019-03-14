#pragma once
#include <string>
#include "GUI.h"
#include "Window.h"
#include "Graph.h"
#include "Person.h"

using namespace Graph_lib;

static constexpr int winX{ 400 };
static constexpr int winY{ 300 };
static constexpr int sepLeft{30};
static constexpr int sepRight{30};
static constexpr int sepTop{30};
static constexpr int sepBot{30};
static constexpr int btnW{70};
static constexpr int btnH{20};
static constexpr int sepButton{45};
static constexpr int fieldW{150};
static constexpr int fieldH{30};
static constexpr int sepField{ 45 };

static string quitBtnTitle{ "Quit" };
static Point quitBtnPoint{ winX - sepRight - btnW, winY - sepBot - btnH };

static string personNewTitle{ "addPerson(..)" };
static Point personNewPoint{sepLeft, winY - sepBot - btnH };

static string personNameTitle{ "Name" };
static Point personNamePoint{ 2*sepLeft, sepTop };

static string personEmailTitle{ "Email" };
static Point personEmailPoint{ 2*sepLeft, personNamePoint.y + fieldH + sepField };


class MeetingWindow : public Window {

public:
	MeetingWindow(Point xy, int w, int h, const string& title);

	static void cbQuit(Address, Address pw);
	static void cbNewPerson(Address, Address pw);

	void addPerson();
	void printPeople() const;
private:
	Point xy;
	int w;
	int h;
	const string title;

	Button quitBtn;
	Button personNewBtn;

	In_box personName;
	In_box personEmail;

	Vector_ref<Person> people;

};
