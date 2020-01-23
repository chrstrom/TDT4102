#include "headers/oppg5.h"

void pythagoras() {
	using namespace Graph_lib;
	constexpr int W = 900;
	constexpr int H = 900;
	constexpr int startX = 100;
	constexpr int startY = 100;

	constexpr int L_X = 350;
	constexpr int topL_Y = 350;
	constexpr int botR_X = 550;
	constexpr int bot_Y = 600;
	// The distances between the two points of the shared edge of the square/triangle
	// BEWARE that these change for every square
    int dx = -1;
	int dy = -1;

	Simple_window win{Point{startX, startY}, W, H, "Pythagoras"};

	// All shapes
	Polygon tri;
	Polygon sq1;
	Polygon sq2;
	Polygon sq3;


	// Middle triangle
	// The three corners
	Point topL_P{L_X, topL_Y};
	Point botR_P{botR_X, bot_Y};
	Point botL_P{L_X, bot_Y};
	tri.add(topL_P);
	tri.add(botR_P);
	tri.add(botL_P);
	
    // Hyp
	dx = abs(L_X - botR_X);
	dy = abs(topL_Y - bot_Y);
	
	sq1.add(topL_P);
	sq1.add(botR_P);
	sq1.add({botR_X + dy, bot_Y - dx});
	sq1.add({L_X + dy, topL_Y - dx});

	// Short side
	dx = abs(L_X - botR_X);
	dy = abs(bot_Y - bot_Y);

	sq2.add(botL_P);
	sq2.add({L_X + dy, bot_Y + dx});
	sq2.add({botR_X + dy, bot_Y + dx});
	sq2.add(botR_P);
	
	// Long side
	dx = abs(L_X - L_X);
	dy = abs(bot_Y - topL_Y);

	sq3.add(botL_P);
	sq3.add({L_X - dy, bot_Y + dx});
	sq3.add({L_X - dy, topL_Y + dx});  
	sq3.add(topL_P);

	// Set colors for the three squares
	tri.set_fill_color(Color::black);
	sq1.set_fill_color(Color::red);
	sq2.set_fill_color(Color::blue);
	sq3.set_fill_color(Color::green);      
	
	// Attach all shapes to window
	win.attach(tri);
	win.attach(sq1);
	win.attach(sq2);
	win.attach(sq3);

	win.wait_for_button();
}