#pragma once
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <utility>
#include <tuple>
#include "utilities.h"

class Vehicle: public Fl_Widget {
    public:
        Vehicle(double x, double y, double angle):
        Fl_Widget(10, 10, 10, 10) 
        {
            ps.x = x;
            ps.y = y;
            ps.angle = angle;
        };
        virtual void draw() final;
    protected:
        virtual std::pair<double, double> steer() const = 0;
        virtual void drawBody() = 0;
        PhysicsState ps;
};

class PlayerVehicle: public Vehicle {
    public:
        PlayerVehicle(double x, double y, double angle) : Vehicle(x, y, angle) {};
        void drawBody();
        std::pair<double, double> steer() const;
};