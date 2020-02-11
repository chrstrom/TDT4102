#pragma once

#include <string>
#include <map>

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

struct MMWindow : Simple_window {
    //using Simple_window::Simple_window;

    MMWindow(Point xy, int w, int h, const string& title, int bl, int wh, Point RP, Point CP)
    : Simple_window(xy, w, h, title), bl{bl}, wh{wh}, RP{RP}, CP{CP} {}
    vector<vector<Shape*>> rectangles;
    vector<vector<Shape*>> circles;

    int bl;
    int wh;

    Point RP;
    Point CP;

    void initGraphics();
    void updateGraphics(const string s);
    void revealCode(const string code);

    void attachShape(vector<Shape*> vs);
};

static map<char, Color::Color_type> codeColorMap{
    {'A', Color::dark_red},
    {'B', Color::dark_blue},
    {'C', Color::dark_yellow},
    {'D', Color::dark_green},
    {'E', Color::magenta},
    {'F', Color::white},
    {'X', Color::black}
};

vector<Shape*> createRectangleArray(Point tl,  int w, int h, int sep, int amt);
vector<Shape*> createCircleArray(Point center, int r, int sep, int amt);