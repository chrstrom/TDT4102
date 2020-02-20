#pragma once

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Window.h"

class Emoji {

public:
    virtual void attach_to(Graph_lib::Window&) = 0;
};