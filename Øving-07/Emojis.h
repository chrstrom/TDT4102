#pragma once
#include "Emoji.h"

class EmptyFace : public Face {

public:
	EmptyFace(Point center, const int radius);
	void attachTo(Graph_lib::Window& win) override;
	
private:
	int eyeRadius;
	Point leftEyeCenter;
	Point rightEyeCenter;

protected:
	Circle rightEye{ rightEyeCenter, eyeRadius };
	Circle leftEye{ leftEyeCenter, eyeRadius };
};

//A
class SmilingFace : public EmptyFace {
public:
	SmilingFace(Point center, int radius);

	void attachTo(Graph_lib::Window& win) override;

private:
	Point mouthStart;
	int mouthWidth;
	int mouthHeight;
	int startDeg;
	int endDeg;

	Arc mouth{ mouthStart, mouthWidth, mouthHeight, startDeg, endDeg };
};

//B
class SadFace : public EmptyFace {
//Velger å arve fra EmptyFace siden det muligens er enklere å tegne ny munn enn å rotere munn fra SmilingFace
//Kan kanskje lage en baseklasse "FaceWithMouth" og endret på denne?
//Eller så kan SmilingFace være denne baseklassen??

public:
	SadFace(Point center, int radius);
	void attachTo(Graph_lib::Window& win) override;

private:
	Point mouthStart;
	int mouthWidth;
	int mouthHeight;
	int startDeg;
	int endDeg;

	Arc mouth{ mouthStart, mouthWidth, mouthHeight, startDeg, endDeg };
};

//C
class AngryFace : public SadFace {
public:
	AngryFace(Point center, int radius);

	void attachTo(Graph_lib::Window& win) override;
private:
	//Max and min eyebrow level are equal for both eyebrows
	int maxY;
	int minY;

	//Left eyebrow
	int topLeftX;
	int botLeftX;
	
	Point topLeft{ topLeftX, maxY };
	Point botLeft{ botLeftX, minY };

	Line leftEyebrow{ topLeft, botLeft };

	//Right eyebrow
	int topRightX;
	int botRightX;

	Point topRight{ topRightX, maxY };
	Point botRight{ botRightX, minY };

	Line rightEyebrow{ topRight, botRight };
};

//D
class WinkingFace : public EmptyFace {
public:
	WinkingFace(Point center, const int radius);

	void attachTo(Graph_lib::Window& win) override;

private:
	const int startDegEye{ 0 };
	const int endDegEye{ 180 };
	const int startDegMouth{ 180 };
	const int endDegMouth{ 360 };

	int eyeRadius;
	int mouthWidth;
	int mouthHeight;

	Point winkingEyeCenter;
	Point mouthStart;

	Arc winkingEye{ winkingEyeCenter, 7*eyeRadius/4, 7*eyeRadius/4, startDegEye, endDegEye };

	Arc mouth{ mouthStart, mouthWidth, mouthHeight, startDegMouth, endDegMouth };
};

//E
class SurprisedFace : public EmptyFace {
public:
	SurprisedFace(Point center, const int radius);

	void attachTo(Graph_lib::Window& win) override;
private:

	const int mouthWidth;
	const int mouthHeight;

	Point mouthCenter;
	Ellipse mouth{ mouthCenter, mouthWidth, mouthHeight };
};


void drawEmojis(Graph_lib::Window& win);

Vector_ref<Emoji> initVector();