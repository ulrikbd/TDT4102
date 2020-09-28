#include "std_lib_facilities.h"


double acclY();

double velY(double initVelocityY, double time);

double posY(double initPositionY, double initVelocityY, double time);
double posX(double initPositionX, double initVelocityX, double time);

void printTime(double time);

double flightTime(double initVelocityY);

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTravelled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);
