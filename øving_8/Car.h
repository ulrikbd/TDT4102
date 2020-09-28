#pragma once
#include "std_lib_facilities.h"


class Car {
    private:
        int freeSeats;
    public:
        Car(int freeSeats): freeSeats{freeSeats} {};
        bool hasFreeSeat() const;
        void reserveFreeSeat();
};
