#include "Tile.h"

// Color for number on tile, depending on amount of mines nearby
const map<int, Color> minesToColor{
	{1, Color::blue},
	{2, Color::red},
	{3, Color::dark_green},
	{4, Color::dark_magenta},
	{5, Color::dark_blue},
	{6, Color::dark_cyan},
	{7, Color::dark_red},
	{8, Color::dark_yellow}
};

const map<Cell, string> cellToSymbol{
	{Cell::closed, ""},
	{Cell::open, ""},
	{Cell::flagged, "@<"}
};

void Tile::open() {
	if(state == Cell::flagged) {
		return;
	}
	
	if(mine) {
		set_label("X");
		set_label_color(Color::red);
	}

	static_cast<Fl_Button*>(pw)->set();
	state = Cell::open;
}

void Tile::flag() {
	if(state == Cell::flagged) {
		state = Cell::closed;
		set_label(cellToSymbol.at(state));
	}
	else {
		state = Cell::flagged;
		set_label(cellToSymbol.at(state));
		set_label_color(Color::blue);
	}
}

void Tile::setAdjacentMines(int n) {
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}