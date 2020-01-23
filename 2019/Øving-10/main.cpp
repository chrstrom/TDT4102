#include "MinesweeperWindow.h"

int main() {
	Fl::background(200, 200, 200);

	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 5;


	while (true) {
		Point startPoint{ 200, 300 };
		MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
		gui_main();
		mw.displayClosingMessage();

		if (mw.choice == 0) { break; }
	}

	string s;
	getline(cin, s);

	return 0;
}
 