#pragma once
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;

class Emoji {

public:
	Emoji() {};
	virtual ~Emoji() {};

	Emoji(const Emoji&) = delete;
	Emoji& operator= (const Emoji&) = delete;

	virtual void attachTo(Graph_lib::Window& win) = 0;
};

class Face : public Emoji {

public:
	Face(Point& center, int radius);

	Face(const Face&) = delete;
	Face& operator= (const Face&) = delete;
	virtual ~Face() {};

	virtual void attachTo(Graph_lib::Window& win) override;

private:
	Point center;
	int radius;
	Circle blankFace{ center, radius };


};

