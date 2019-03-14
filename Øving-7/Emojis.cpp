#include "Emojis.h"

EmptyFace::EmptyFace(Point center, const int radius) 
		: Face{ center, radius }, eyeRadius{radius/5}, 
		  leftEyeCenter{ center.x - radius/3, center.y - radius/5 },
		  rightEyeCenter{ center.x + radius/3, center.y - radius/5 }
{
	leftEye.set_fill_color(Color::black);
	leftEye.set_color(Color::black);

	rightEye.set_fill_color(Color::black);
	rightEye.set_color(Color::black);
}

void EmptyFace::attachTo(Graph_lib::Window& win) {
	Face::attachTo(win);

	win.attach(rightEye);
	win.attach(leftEye);
}


//A
SmilingFace::SmilingFace(Point center, const int radius)
	: EmptyFace{ center, radius },  startDeg{ 180 }, endDeg{ 360 },
	  mouthWidth{ radius }, mouthHeight{ 3*radius / 4 }, 
	  mouthStart{ center.x, center.y+ radius/5}
{
	mouth.set_color(Color::black);
	Line_style style{ Line_style::solid, radius/15 };

	mouth.set_style(style);
}

void SmilingFace::attachTo(Graph_lib::Window& win) {
	EmptyFace::attachTo(win);

	win.attach(mouth);
}


//B
SadFace::SadFace(Point center, int radius) 
	: EmptyFace{ center, radius }, startDeg{ 0 }, endDeg{ 180 },
	  mouthWidth{radius}, mouthHeight{3*radius/4},
	  mouthStart{center.x, center.y+radius/2}
{
	mouth.set_color(Color::black);
	Line_style style{ Line_style::solid, radius/15 };

	mouth.set_style(style);
}

void SadFace::attachTo(Graph_lib::Window& win) {
	EmptyFace::attachTo(win);
	win.attach(mouth);
}

//C
AngryFace::AngryFace(Point center, const int radius)
	 : SadFace{ center, radius },
	   maxY{center.y - 2*radius/3}, minY{center.y - radius/3},
	   topLeftX{center.x - 2*radius/3 },	 botLeftX{center.x - radius/7},
	  topRightX{center.x + 2*radius/3 },	botRightX{center.x + radius/7}
{
	Line_style eyebrowStyle{ Line_style::solid, radius/15 };

	rightEyebrow.set_color(Color::black);
	rightEyebrow.set_style(eyebrowStyle);

	leftEyebrow.set_color(Color::black);
	leftEyebrow.set_style(eyebrowStyle);
}

void AngryFace::attachTo(Graph_lib::Window& win) {
	SadFace::attachTo(win);

	win.attach(leftEyebrow);
	win.attach(rightEyebrow);
}


//D
WinkingFace::WinkingFace(Point center,const int radius)
	: EmptyFace{center, radius}, 
	  eyeRadius{radius/5},
	  winkingEyeCenter{ center.x + radius / 3, center.y - radius / 8 },
	  mouthWidth{ radius }, mouthHeight{ 3 * radius / 4 },
	  mouthStart{ center.x, center.y + radius / 5 }
{
	mouth.set_color(Color::black);
	Line_style style{ Line_style::solid, radius / 15 };

	mouth.set_style(style);

	winkingEye.set_fill_color(Color::black);
	winkingEye.set_color(Color::black);
	winkingEye.set_style(style);

}

void WinkingFace::attachTo(Graph_lib::Window& win) {
	EmptyFace::attachTo(win);
	win.detach(EmptyFace::rightEye);

	win.attach(winkingEye);
	win.attach(mouth);
}


//E
SurprisedFace::SurprisedFace(Point center, const int radius)
	: EmptyFace{ center, radius },
	  mouthCenter{ center.x, center.y + radius/2},
	  mouthWidth{radius/2}, mouthHeight{radius/3}
{
	mouth.set_color(Color::black);
	mouth.set_fill_color(Color::black);
}

void SurprisedFace::attachTo(Graph_lib::Window& win) {
	EmptyFace::attachTo(win);
	win.attach(mouth);
}

void  drawEmojis(Graph_lib::Window& win) {
	constexpr int xStep{ 180 };
	constexpr int y{ 300 };
	constexpr int radius{ 60 };
	int i{ 1 };

	static SmilingFace smilingFace{ { xStep*i, y }, radius }; i++;
	smilingFace.attachTo(win);

	static SadFace sadFace{ { xStep*i, y }, radius }; i++;
	sadFace.attachTo(win);

	static AngryFace angryFace{ { xStep*i, y }, radius }; i++;
	angryFace.attachTo(win);

	static WinkingFace winkingFace{ { xStep*i, y }, radius }; i++;
	winkingFace.attachTo(win);

	static SurprisedFace surprisedFace{ { xStep*i, y }, radius };
	surprisedFace.attachTo(win);

	//Read Access violation error ved å legge inn emojis inn i Vector_ref. Brute-forcer isteden.
}

Vector_ref<Emoji> initVector() {
	Vector_ref<Emoji> vec;

	constexpr int xStep{ 180 };
	constexpr int y{ 300 };
	constexpr int radius{ 60 };
	int i{ 1 };

	static SmilingFace smilingFace{ { xStep*i, y }, radius }; i++;
	static SadFace sadFace{ { xStep*i, y }, radius }; i++;
	static AngryFace angryFace{ { xStep*i, y }, radius }; i++;
	static WinkingFace winkingFace{ { xStep*i, y }, radius }; i++;
	static SurprisedFace surprisedFace{ { xStep*i, y }, radius };

	vec.push_back(smilingFace);
	vec.push_back(sadFace);
	vec.push_back(angryFace);
	vec.push_back(winkingFace);
	vec.push_back(surprisedFace);


	return vec;
}


