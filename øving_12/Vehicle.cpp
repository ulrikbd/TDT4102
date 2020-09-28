#include "Vehicle.h"

void Vehicle::draw() {
    std::pair<double, double> acc = steer();

    ps.update(acc.first, acc.second);
    
    drawBody();
}

void PlayerVehicle::drawBody() {
    fl_color(FL_BLACK);
    fl_circle(ps.x, ps.y, 50.0);
}

std::pair<double, double> PlayerVehicle::steer() const{
    std::pair<double, double> acc(0, 0);
    if (Fl::event_key() == FL_Left) {
        acc.first = 0.5;
        acc.second = 1;
    }
    else if (Fl::event_key() == FL_Right) {
        acc.first = 0.5;
        acc.second = -1;
    }
    else if (Fl::event_key() == FL_Down) {
        acc.first = 0.5;
        acc.second = -0.5;
    }
    else if (Fl::event_key() == FL_Up) {
        acc.first = 0.5;
        acc.second = 0.5;
    }
    return acc;
}