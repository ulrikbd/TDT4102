#include "std_lib_facilities.h"


double discriminant(double a, double b, double c) {
    double disc = pow(b, b) - 4*a*c;
    return disc;
}   

void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);
    if (disc > 0) {
        double x1 = (-b + sqrt(disc)) / (2*a);
        double x2 = (-b - sqrt(disc)) / (2*a);
        cout << "De reelle røttene er: " << x1 << " og " << x2 << endl;
    } else if (disc == 0) {
        double x1 = -b/ (2*a);
        cout << "Den reelle roten er: " << x1 << endl;
    } else {
        cout << "ingen reelle røtter" << endl;
    }
}

void solveQuadraticEquation() {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl;

    cout << "b: ";
    cin >> b;
    cout << endl;

    cout << "c: ";
    cin >> c;
    cout << endl;

    printRealRoots(a, b, c);
}

