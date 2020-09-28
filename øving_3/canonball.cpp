#include "canonball.h"


constexpr double pi = 3.14159265359;

//Oppgave a)
double acclY() {
    return -9.81;
}

//b)
double velY(double initVelocityY, double time) {
    double velocity = initVelocityY + acclY()*time;
    return velocity;
}

//c)
double posY(double initPositionY, double initVelocityY, double time) {
    double position = initPositionY + initVelocityY*time + 1.0/2*acclY()*pow(time, 2);
    return position;
}

double posX(double initPositionX, double initVelocityX, double time) {
    double position = initPositionX + initVelocityX*time;
    return position;
}


//d)
void printTime(double time) {
    int timeInt = round(time);
    int hours = timeInt / 3600;
    int remainder = timeInt % 3600;
    int minutes = remainder / 60;
    remainder = remainder % 60;

    cout << hours << " hours, " << minutes << " minutes and " << remainder << " seconds.";
}

//e)
double flightTime(double initVelocityY) {
    double time = -2.0*initVelocityY/acclY();
    return time;
}

//Oppgave 4a)
double getUserInputTheta() {
    cout << "Angle in degrees: ";
    double theta;
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    cout << "Absolute velocity: ";
    double absVelocity;
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg) {
    double rad = deg*pi/180.0;
    return rad;
}

double getVelocityX(double theta, double absVelocity) {
    double velocityX = absVelocity*cos(theta);
    return velocityX;
}

double getVelocityY(double theta, double absVelocity) {
    double velocityY = absVelocity*sin(theta);
    return velocityY;
}

vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> velocityVector{getVelocityX(theta, absVelocity), getVelocityY(theta, absVelocity)};
    return velocityVector;
}

//b)
double getDistanceTravelled(double velocityX, double velocityY) {
    double flightT = flightTime(velocityY);
    double distanceTravelled = velocityX*flightT;
    return distanceTravelled;
}

//c)
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double distanceTravelled = getDistanceTravelled(velocityX, velocityY);
    double distanceMissed = abs(distanceTravelled - distanceToTarget);
    
    return distanceMissed;
}


