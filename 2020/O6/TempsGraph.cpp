#include "TempsGraph.h"

constexpr int STEP = 80;
const Font labelFont = Font::helvetica;
const Font labelFontB = Font::helvetica_bold;

void drawAxis(Simple_window& win) {
	const int X_Len = win.x_max() - 2.5 * STEP;
    	const int Y_Len = win.y_max() - 2.0 * STEP;
	constexpr int X_Ticks = 12;
    	constexpr int Y_Ticks = 6;

	string X_Label = "";
    	string Y_Label = "degrees [C]";

	Point X_Start{ STEP, win.y_max() / 2 };
    	Point Y_Start{ STEP, win.y_max() - STEP };

	static Axis xAxis(Axis::x, X_Start, X_Len, X_Ticks, X_Label);
    	static Axis yAxis(Axis::y, Y_Start, Y_Len, Y_Ticks, Y_Label);

	xAxis.set_color(Color::black);
    	yAxis.set_color(Color::black);

	win.attach(xAxis);
    	win.attach(yAxis);
}

void addTextXAxis(Simple_window& win) {
	constexpr int stepText = 91;
	constexpr int X_Off = 2 * STEP - 20;
	const int Y_Off = win.y_max() / 2 + 15;
	const vector<string> months{"Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", "Jan"};

    	static vector<Text*> X_Text;
	for (int i = 0; i < months.size(); i++) {
		X_Text.push_back(new Text{{X_Off + i*stepText, Y_Off}, months[i]});
		X_Text.back()->set_color(Color::black);
		X_Text.back()->set_font(labelFont);
		win.attach(*X_Text.back());
	}
}


void addTextYAxis(Simple_window& win) {
    // Labels
	constexpr int Y_Off = 2.5 * STEP;
	constexpr int stepText = 130;
	vector<string> Y_Labels{"20", "10", "0", "-10", "-20"};
	
    	static vector<Text*> Y_Text;
	for (int i = 0; i < Y_Labels.size(); i++) {
		Y_Text.push_back(new Text{{STEP/2, Y_Off + stepText*i}, Y_Labels[i]});
		Y_Text.back()->set_color(Color::black);
		Y_Text.back()->set_font(labelFont);
		win.attach(*Y_Text.back());
	}
    
    // Legend
    	Point maxPoint{ STEP / 4 , win.y_max() / 2 + 50 };
    	Point minPoint{ STEP / 4 , win.y_max() / 2 + 125 };

	static Text max{ maxPoint, "Max" };
    	static Text min{ minPoint, "Min" };

	max.set_color(Color::red);
    	min.set_color(Color::blue);

	max.set_font(labelFontB);
    	min.set_font(labelFontB);
     
	win.attach(max);
	win.attach(min);
}

void drawTempsOpls(Simple_window& win, const vector<Temps>& temperatures) {
	constexpr int X_Step = 3;
	constexpr int Y_Step = 10;
	Point origin{STEP, win.y_max()/2};

	static Open_polyline OplMax;
    	static Open_polyline OplMin;
	for (int i = 0; i < temperatures.size(); i++) {
		int X_Max = origin.x + X_Step * i;
        int X_Min = origin.x + X_Step * i;

		int Y_Max = origin.y - Y_Step * temperatures[i].max;
        int Y_Min = origin.y - Y_Step * temperatures[i].min;

		OplMax.add(Point{ X_Max, Y_Max });
        OplMin.add(Point{ X_Min, Y_Min });
	}
	
	OplMax.set_color(Color::red);
	OplMin.set_color(Color::blue);

    	OplMax.set_style({Line_style::solid, 1});
	OplMin.set_style({Line_style::solid, 1});

   	win.attach(OplMax);
	win.attach(OplMin);
}

void drawTempGraph(const vector<Temps>& temperatures) {
    	constexpr int winH = 900;
    	constexpr int winW = 1300;
    	Simple_window win{{100, 40}, winW, winH, "Temperatures"};

    	drawAxis(win);
    	addTextXAxis(win);
    	addTextYAxis(win);
	drawTempsOpls(win, temperatures);

    	win.wait_for_button();
}
