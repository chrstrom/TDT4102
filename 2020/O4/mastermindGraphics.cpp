#include "headers/mastermindGraphics.h"

// Globals for GUI layout
constexpr int REC_W = 40;
constexpr int REC_H = 20;
constexpr int REC_AMT = 4;
constexpr int REC_SEP = 20;

constexpr int CIR_R = 5;
constexpr int CIR_SEP = 5;
constexpr int CIR_SEP_Y = 40;
constexpr int CIR_AMT = 4;

using namespace Graph_lib;

void MMWindow::initGraphics() {
    // Rectangles for code
    rectangles.push_back(createRectangleArray(RP, REC_W, REC_H, REC_SEP, REC_AMT));
     for(int i = 0; i < rectangles.back().size(); i++) {
        rectangles.back()[i]->set_fill_color(Color::black);
    }
    attachShape(rectangles.back());

    RP.y += 100;
    CP.y += 60;

    rectangles.push_back(createRectangleArray(RP, REC_W, REC_H, REC_SEP, REC_AMT));
    attachShape(rectangles.back());

    circles.push_back(createCircleArray(CP, CIR_R, CIR_SEP, CIR_AMT));
    attachShape(circles.back());
}

void MMWindow::updateGraphics(const string s) {
    vector<Shape*> latestRect = rectangles.back();
    vector<Shape*> latestCirc = circles.back();

    // Update offsets in win
    RP.y += (REC_H + REC_SEP);
    CP.y += (CIR_SEP_Y);

    // Set color for each rectangle and circle, and attach to window
    for(int i = 0; i < latestRect.size(); i++) {
        latestRect[i]->set_fill_color(codeColorMap[s[i]]);
    }
    attachShape(latestRect);

    // Set bl and wh for circles
    for(int i = 0; i < wh; i++) {
        if(i < wh) {
            latestCirc[i]->set_fill_color(Color::white);
        }
        else if (i > wh && i < wh + bl) {
            latestCirc[i]->set_fill_color(Color::black);
        }
    }
    attachShape(latestCirc);
 
    // Draw new rectangles (not filled) and attach
    rectangles.push_back(createRectangleArray(RP, REC_W, REC_H, REC_SEP, REC_AMT));
    attachShape(rectangles.back());

    // Draw new circles (not filled) and attach
    circles.push_back(createCircleArray(CP, CIR_R, CIR_SEP, CIR_AMT));
    attachShape(circles.back());
}

void MMWindow::revealCode(const string code) {
    
    for(int i = 0; i < rectangles.front().size(); i++) {
        rectangles.front()[i]->set_fill_color(codeColorMap[code[i]]);
    }
    
    attachShape(rectangles.front());
}

void MMWindow::attachShape(vector<Shape*> vs) {
    for(const auto& s : vs) {
        attach(*s);
    }
}

vector<Shape*> createRectangleArray(Point tl, int w, int h, int sep, int amt) {
    vector<Shape*> v;
    
    for(int i = 0; i < amt; i++) {
        v.push_back(new Rectangle{tl, w, h});

        // Increment in x-direction
        tl.x += sep + w;
    }

    return v;
}

vector<Shape*> createCircleArray(Point center, int r, int sep, int amt) {
    vector<Shape*> s;
    int len = sqrt(amt);
    sep += r;                                   // sep needs to include the radius

    for(int i = 0; i < len; i++) {              // Draw row by row, line by line
        for(int j = 0; j < len; j++) {
            s.push_back(new Circle{center, r});
            center.x += sep;
        }
        // Reset the x offset, add y offset
        center.x -= (len * sep);
        center.y += sep;
    }
    return s;
}
