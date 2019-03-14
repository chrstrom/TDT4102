#include "Emoji.h"

Face::Face(Point& center, const int radius) : center{ center }, radius{ radius }
{
	blankFace.set_fill_color(Color::yellow);
};

void Face::attachTo(Graph_lib::Window& win) {
	win.attach(blankFace);
}