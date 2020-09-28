#include "Car.h"

bool Car::hasFreeSeat() const {
    if (freeSeats == 0) return false;
    else return true;
}

void Car::reserveFreeSeat() {
    freeSeats--;
}