#pragma once
#include "std_lib_facilities.h"

struct Temps {
    double min;
    double max;
    friend istream& operator>>(istream& is, Temps& t);
};

//Trenger jeg friend her når jeg ikke har 
//private variabler i structen?

vector<Temps> tempsToVector(string filename);