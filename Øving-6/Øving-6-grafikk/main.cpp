#include "Simple_window.h"
#include "Graph.h"
#include "graphics.h"
#include "logic.h"

int main() {
	//Constants for window size
	constexpr int winWidth{ 1300 };
	constexpr int winHeight{ 800 };

	//Create window
	Simple_window win{ Point{0, 0}, winWidth, winHeight, "Oppgave 5 øving 6" };

	//Draw axis
	drawAxis(win, winHeight, winWidth);

	//Add numbers to y-axis
	addTextYAxis(win, winHeight);
	//Add text to x-axis
	addTextXAxis(win, winHeight, winWidth);

	//Draw max and min temperatures
	drawTemps(win, winHeight);

	


	win.wait_for_button();

	return 0;
}

