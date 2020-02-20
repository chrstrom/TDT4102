#pragma once

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Window.h"

class Emoji {

public:
    Emoji() = default;
    Emoji(const Emoji&) = delete;
    Emoji& operator=(const Emoji&) = delete;

    virtual void attach_to(Graph_lib::Window&) = 0;

    virtual ~Emoji() {};
};