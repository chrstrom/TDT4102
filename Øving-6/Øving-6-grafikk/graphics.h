#pragma once
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "logic.h"

void drawAxis(Simple_window& win, const int winHeight, const int winWidth);

void addTextYAxis(Simple_window& win, const int winHeight);
void addTextXAxis(Simple_window& win, const int winHeight, const int winWidth);

void drawTemps(Simple_window& win, const int winHeight);
