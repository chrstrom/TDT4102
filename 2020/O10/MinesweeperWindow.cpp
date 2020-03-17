#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title},
	width{width}, height{height}, tilesLeft{width * height - mines}
{
	for(int h = 0; h < height; ++h) {
		for(int w = 0; w < width; ++w) {
			tiles.push_back(new Tile{ Point{w * cellSize, h * cellSize}, cellSize, cb_click});
			attach(*tiles.back());
		}
	}

	//Add mines at random locations
	int mine = 0;
	while(mine < mines) {
		int idx = rand() % tiles.size();
		if(!tiles[idx]->isMine()) {
			mine++;
			tiles[idx]->setMine();
		} 
	}

	// Remove scalability of window
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int count = 0;
	for(Point p : points)
		if(at(p).isMine())
			count++;
	
	return count;
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int dw = -1; dw <= 1; dw++) {
		for (int dh = -1; dh <= 1; dh++) {
			if (dw == 0 && dh == 0) {
				continue;
			}

			Point neighbour{ xy.x + dw * cellSize,xy.y + dh * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& t = at(xy);

	if(t.getState() != Cell::closed)
		return;
	
	if(t.isMine()) {
		gameEnded = true;
		endGame();
		return;
	}

	t.open();

	if(!gameEnded) 
		tilesLeft--;

	if(tilesLeft == 0) {
		gameEnded = true;
		endGame();
	}

	vector<Point> adj = adjacentPoints(xy);
	int adjMines = countMines(adj);

	if(adjMines) {
		t.setAdjacentMines(adjMines);
		return;
	}
	
	// Recursively open all connected tiles with 0 adjacent mines
	for(Point p : adj) 
		openTile(p);
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& t = at(xy);

	if(t.getState() != Cell::open)
		t.flag();
}

void MinesweeperWindow::cb_click(Address, Address pw) {
	Point xy{ Fl::event_x(), Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy))
		return;

	switch(mb) {
		case MouseButton::left:
			win.openTile(xy);
			break;
		case MouseButton::right:
			win.flagTile(xy);
			break;
	}

	win.flush();
}


void MinesweeperWindow::endGame() {
	static Text feedback{Point{x_max()/5, y_max()/4}, tilesLeft ? "You lost!" : "You win!"};

	feedback.set_font_size(40);
	feedback.set_color(Color::black);
	attach(feedback);

	for(Tile* t : tiles) {
		if(t->getState() == Cell::flagged) 
			t->flag();	// Reset flags set by user because they are independent from ending flags.
		t->isMine() ?  (tilesLeft ? t->open() : t->flag()) : openTile(t->loc);
	}
}
