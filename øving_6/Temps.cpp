#include "Temps.h"

istream& operator>>(istream& is, Temps& t) {
    is >> t.min >> t.max;
    return is;
}

vector<Temps> tempsToVector(string filename) {
    vector<Temps> temps;
    ifstream in{filename};
    Temps t;
    while (in) {
        in >> t;
        temps.push_back(t);
    }
    return temps;
}