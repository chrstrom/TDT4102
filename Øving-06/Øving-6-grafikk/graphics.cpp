#include "graphics.h"

//Separation constant used for spacing in creating graphics
constexpr int stdSep{ 80 };

void drawAxis(Simple_window& win, const int winHeight, const int winWidth) {
	//x axis
	const int xAxisLen{ winWidth - 3 * stdSep + stdSep / 2 };
	constexpr int xAxisTicks{ 12 };
	string xAxisLab{ "" };
	Point xAxisStart{ stdSep, winHeight / 2 };

	static Axis xAxis(Axis::x, xAxisStart, xAxisLen, xAxisTicks, xAxisLab);

	xAxis.set_color(Color::black);

	win.attach(xAxis);


	//y axis
	const int yAxisLen{ winHeight - 2 * stdSep };
	constexpr int yAxisTicks{ 6 };
	string yAxisLab{ "degrees [C]" };
	Point yAxisStart{ stdSep, winHeight - stdSep };

	static Axis yAxis(Axis::y, yAxisStart, yAxisLen, yAxisTicks, yAxisLab);

	yAxis.set_color(Color::black);

	win.attach(yAxis);
}

void addTextYAxis(Simple_window& win, const int winHeight) {

	//"Max"
	Point maxPoint{ stdSep / 4 , winHeight / 2 + 50 };
	static Text max{ maxPoint, "Max" };
	max.set_color(Color::red);
	max.set_font(Font::helvetica_bold);

	win.attach(max);

	//"Min"
	Point minPoint{ stdSep / 4 , winHeight / 2 + 125 };
	static Text min{ minPoint, "Min" };
	min.set_color(Color::blue);
	min.set_font(Font::helvetica_bold);

	win.attach(min);

	//Numbers 20 to -20
	constexpr int offsetY{ 2*stdSep + stdSep/2};
	constexpr int textStep{ 105 };
	
	static Vector_ref<Text> yAxisText;
	vector<string> yAxisNumbers{"20", "10", "0", "-10", "-20"};
	
	for (int i = 0; i < yAxisNumbers.size(); i++) {
		Point currentPoint{stdSep/2, offsetY + textStep*i};
		yAxisText.push_back(new Text{ currentPoint, yAxisNumbers[i] });
	}

	for (int i = 0; i < yAxisText.size(); i++) {
		yAxisText[i].set_color(Color::black);
		yAxisText[i].set_font(Font::helvetica);

		win.attach(yAxisText[i]);
	}
}
void addTextXAxis(Simple_window& win, const int winHeight, const int winWidth) {
	constexpr int textStep{ 91 };
	constexpr int offsetX{ 2 * stdSep - 20 };
	const int offsetY{ winHeight / 2 + 15 };

	static Vector_ref<Text> xAxisText;
	vector<string> months{ "Feb" , "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", "Jan" };			//kan kanskje også bruke enum

	//add text to Vector_ref
	for (int i = 0; i < months.size(); i++) {
		Point currentPoint{offsetX + i*textStep, offsetY};
		xAxisText.push_back(new Text{ currentPoint, months[i] });
	}

	//add text from Vector_ref to win
	for (int i = 0; i < xAxisText.size(); i++){
		xAxisText[i].set_color(Color::black);
		xAxisText[i].set_font(Font::helvetica);
		win.attach(xAxisText[i]);
	}
}


void drawTemps(Simple_window& win, const int winHeight) {
	constexpr int xAxisScale{ 3 };					//stepLen is the norm of x_i - x_(i-1)
	constexpr int yAxisScale{ 10 };
	Point origin{ stdSep, winHeight / 2 };

	const string tempsFile{ "temperatures" };
	vector<Temps> temperatures{ readTemps(tempsFile) };

	static Open_polyline OplMax;
	static Open_polyline OplMin;
	Line_style graphLineStyle{ Line_style::solid, 1 };

	//Graph for max temperatures 
	for (int i = 0; i < temperatures.size(); i++) {
		int xCoord{ static_cast<int>(origin.x + xAxisScale * i) };
		int yCoord{ static_cast<int>(origin.y - yAxisScale * temperatures[i].max) };

		OplMax.add(Point{ xCoord, yCoord });
	}
	OplMax.set_color(Color::red);
	OplMax.set_style(graphLineStyle);

	win.attach(OplMax);

	//Graph for min temperatures
	for (int i = 0; i < temperatures.size(); i++) {
		int xCoord{ static_cast<int>(origin.x + xAxisScale * i)};
		int yCoord{ static_cast<int>(origin.y - yAxisScale * temperatures[i].min) };

		OplMin.add(Point{ xCoord, yCoord });
	}
	OplMin.set_color(Color::blue);
	OplMin.set_style(graphLineStyle);

	win.attach(OplMin);
}
