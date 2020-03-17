#pragma once

#include "Window.h"
#include "Tile.h"

using namespace Graph_lib;

enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE };

class MinesweeperWindow : public Graph_lib::Window {
public:

	static constexpr int cellSize = 30;
	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);

	
	int getHeight() const { return height * cellSize; }
	int getWidth() const { return width * cellSize; }

private:
	const int width;
	const int height;
	const int mines;

	vector<Tile*> tiles;
	vector<Point> adjacentPoints(Point xy) const;

	int countMines(vector<Point> coords) const;

	// Utility
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x < getWidth() && xy.y >= 0 && xy.y < getHeight(); }
	Tile& at(Point xy) { return *tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const Tile& at(Point xy) const { return *tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	void openTile(Point xy);
	void flagTile(Point xy);

	static void cb_click(Address, Address pw);
};
