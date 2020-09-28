#include "std_lib_facilities.h"
#include "Graph.h" 
#include "Simple_window.h"

using namespace Graph_lib;

void pythagoras() {
    int w = 1600;
    int h = 800;
    Simple_window win{Point{100,100}, w, h,"Pythagoras"};

    Polygon rightTriangle;

    rightTriangle.add(Point{700, 300});
    rightTriangle.add(Point{700, 500});
    rightTriangle.add(Point{850, 500});
    rightTriangle.set_fill_color(Color::red);

    Polygon hypSquare;

    hypSquare.add(Point{700, 300});
    hypSquare.add(Point{850, 500});
    hypSquare.add(Point{850 + 200, 500 - 150});
    hypSquare.add(Point{700 + 200, 300 - 150});
    hypSquare.set_fill_color(Color::yellow);

    Polygon bottomSquare;

    bottomSquare.add(Point{700, 500});
    bottomSquare.add(Point{850, 500});
    bottomSquare.add(Point{850, 650});
    bottomSquare.add(Point{700, 650});
    bottomSquare.set_fill_color(Color::green);

    Polygon leftSquare;

    leftSquare.add(Point{700, 300});
    leftSquare.add(Point{700, 500});
    leftSquare.add(Point{500, 500});
    leftSquare.add(Point{500, 300});
    leftSquare.set_fill_color(Color::blue);

    win.attach(rightTriangle);
    win.attach(bottomSquare);
    win.attach(leftSquare);
    win.attach(hypSquare);
    win.wait_for_button();
}