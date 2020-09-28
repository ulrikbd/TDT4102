#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int lowerLimit, int upperLimit) {
    int tilfeldig_tall = rand();
    tilfeldig_tall = tilfeldig_tall%(upperLimit - lowerLimit + 1);
    tilfeldig_tall += lowerLimit;
    return tilfeldig_tall;
}
