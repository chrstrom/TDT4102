#include "MinesweeperWindow.h"

int MinesweeperWindow::choice{ 1 };

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, pxTop + height * cellSize, title), flagCounter{0},
	width(width), height(height), mines(mines), state(Gamestate::playing),
	quitBtn{ Point{quitBtnPointX, quitBtnPointY}, btnW, btnH, "Quit", cb_quit },
	resetBtn{ Point{resetBtnPointX, resetBtnPointY}, btnW, btnH, "Reset", cb_reset },
	countOut{ Point{countPointX, countPointY }, boxW, boxH,"" },
	countText{Point{countTextX, countTextY}, "Mines left: "}
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	//Draw buttons
	attach(quitBtn);
	attach(resetBtn);
	attach(countOut);

	countText.set_color(Color::black);

	attach(countText);
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = pxTop + i * cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	random_device rand;
	mt19937_64 randomInt(rand());
	uniform_int_distribution<> randPointVal(0, width);
	uniform_int_distribution<> randTile(0, width*height-1);
	int randTileInt;
	int counter{ 0 };

	while(counter < mines) {
		randTileInt = randTile(randomInt);
		if (!tiles[randTileInt].isMine) {
			tiles[randTileInt].isMine = true;
			counter++;
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


int MinesweeperWindow::countMines(vector<Point> points) const {
	int noOfMines{ 0 };
	for (const auto& P : points) {
		if (at(P).isMine) {
			noOfMines++;
		}
	}
	return noOfMines;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize  };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).state == Cell::closed && state == Gamestate::playing) {

		at(xy).open();
		if (!at(xy).isMine) {
			int noOfMines{ countMines(adjacentPoints(xy)) };

			if (!at(xy).isMine && noOfMines > 0) {
				at(xy).setAdjMines(noOfMines);
			}

			if (noOfMines == 0) {
				vector<Point> points{ adjacentPoints(xy) };
				for (const auto& P : points) {
					openTile(P);
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if ((at(xy).state == Cell::flagged || at(xy).state == Cell::closed) && state == Gamestate::playing) {
		at(xy).flag();
	}

}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() - pxTop };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		win.updateGameState(xy, mb);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		win.updateGameState(xy, mb);
		break;
	}
	win.flush();
}

void MinesweeperWindow::cb_quit(Address, Address pw) {
	auto& win = reference_to<MinesweeperWindow>(pw);
	win.state = Gamestate::lost;
	win.choice = 0;
	win.hide();
}
void MinesweeperWindow::cb_reset(Address, Address pw) {
	auto& win = reference_to<MinesweeperWindow>(pw);
	win.hide();
}

void MinesweeperWindow::updateGameState(Point xy, MouseButton mb) {
	cout << "checkGameState() called.\n";
	
	if (at(xy).state != Cell::flagged) {
		//Game is lost upon pressing a cell that is a mine
		if (state == Gamestate::playing && at(xy).isMine && mb == MouseButton::left) {
			state = Gamestate::lost;
			showMines();
			displayClosingMessage();
		}

		//Game is won upon having opened all cells that aren't mines (height*width - mines)
		if (state == Gamestate::playing) {
			int counter{ 0 };
			for (auto& tile : tiles) {
				if (tile->state == Cell::open) {
					counter++;
				}
			}
			if (counter == height * width - mines) {
				state = Gamestate::won;
				showMines();
				displayClosingMessage();
			}
		}
	}
	updateCounter();
}

void MinesweeperWindow::displayClosingMessage() {
	//It's messy, I know..
	constexpr int sep = 20;
	Point tl{sep, 3*sep};
	Point br{x_max() - sep, 5*sep};
	Point txt{ (br.x - tl.x)/2 - sep/2, tl.y + sep };
	static Rectangle bg{ tl, br };

	attach(bg);

	static Text winMsg{ txt, "You won!" };
	winMsg.set_color(Color::black);
	winMsg.set_font_size(18);

	static Text loseMsg{ txt, "You lost!" };
	loseMsg.set_color(Color::black);
	loseMsg.set_font_size(18);

	switch (state) {
	case Gamestate::won:
		bg.set_fill_color(Color::green);
		bg.set_color(Color::dark_green);
		attach(winMsg);
		cout << "Game won invoked\n";
		break;
	case Gamestate::lost:
		bg.set_fill_color(Color::red);
		bg.set_color(Color::dark_red);
		attach(loseMsg);
		cout << "Game lost invoked\n";
		break;
	}
}

void MinesweeperWindow::updateCounter() {
	cout << "flagAmt in updateCounter():    " << tiles[0].flagAmt << '\n';
	flagCounter = mines - tiles[0].flagAmt;
	cout << "flagCounter:   " << flagCounter << '\n';
	countOut.put(flagCounter);
	cout << "updateCounter() called\n";

}

void MinesweeperWindow::showMines() {
	for (auto& tile : tiles) {
		if (tile->state == Cell::closed || tile->state == Cell::flagged) {
			if (tile->isMine) {
				if (state == Gamestate::lost) {
					tile->open();
				}
				if (state == Gamestate::won && tile->state != Cell::flagged) {
					tile->flag();
				}
			}
		}
	}
}