#pragma once
#include "GUI.h"

using namespace Graph_lib;

enum class Cell { closed, open, flagged };

class Tile : public Button {
public:
	Tile(Point pos, int size, Graph_lib::Callback cb, bool isMine = false) : Button{pos, size, size, "", cb}, mine{isMine} {};

	Cell getState() const {return state;}
	bool isMine() const {return mine;}
	
	void setMine() {mine = true;}
	void setAdjacentMines(int n);

	void open();
	void flag();

private:
	Cell state = Cell::closed;
	bool mine;

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
};