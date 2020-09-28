#include "Emoji.h"

Face::Face(Point c, int r):
face{Circle(c, r)} {
    face.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& w) {
    w.attach(face);
}

emptyFace::emptyFace(Point c, int r): 
Face{c, r}, leftEye{Circle(Point{c.x - r/3, c.y - r/5}, r/6)}, 
rightEye{Circle(Point{c.x + r/3, c.y - r/5}, r/6)} {
    leftEye.set_fill_color(Color::black);
    rightEye.set_fill_color(Color::black);
}

void emptyFace::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
}

smileyFace::smileyFace(Point c, int r): 
emptyFace{c, r}, mouth{Point{c.x, c.y + r/5}, 4*r/3, r, 180, 360} {}

void smileyFace::attach_to(Graph_lib::Window& win) {
    emptyFace::attach_to(win);
    win.attach(mouth);
}

sadFace::sadFace(Point c, int r):
emptyFace{c, r}, mouth{Point{c.x, c.y + r/2}, 4*r/3, r, 0, 180} {}

void sadFace::attach_to(Graph_lib::Window& win) {
    emptyFace::attach_to(win);
    win.attach(mouth);
}

AngryFace::AngryFace(Point c, int r):
sadFace{c, r}, leftEyebrow{Line{Point{c.x - r/3, c.y - r/2}, Point{c.x, c.y - r/5}}},
rightEyebrow{Line{Point{c.x + r/3, c.y - r/2}, Point{c.x, c.y - r/5}}}
{}

void AngryFace::attach_to(Graph_lib::Window& win) {
    sadFace::attach_to(win);
    win.attach(leftEyebrow);
    win.attach(rightEyebrow);
}

SurprisedFace::SurprisedFace(Point c, int r):
emptyFace{c, r}, mouth{Point{c.x, c.y + r/3}, r/2, r/2, 0, 360} {}

void SurprisedFace::attach_to(Graph_lib::Window& win) {
    emptyFace::attach_to(win);
    win.attach(mouth);
}

WinkingFace::WinkingFace(Point c, int r):
Face{c, r}, leftEye{Arc{Point{c.x - r/3, c.y - r/5}, r/3, r/3, 0, 180}},
rightEye{Circle(Point{c.x + r/3, c.y - r/5}, r/6)}, 
mouth{Point{c.x, c.y + r/5}, 4*r/3, r, 180, 360}
{
    rightEye.set_fill_color(Color::black);
}

void WinkingFace::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
    win.attach(mouth);
}