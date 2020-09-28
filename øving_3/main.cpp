#include "std_lib_facilities.h"
#include "canonball.h"
#include "utilities.h"


void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void playTargetPractice();

constexpr double maxError = 0.0001;

int main()
{
	//3a) Tester funksjonene
	// printTime(3662);
	// cout << '\n';
	// testDeviation(velY(25.0, 2.5), 0.475,  maxError, "velY(25.0, 2.5)");
	// testDeviation(velY(25.0, 5.0), -24.05,  maxError, "velY(25.0, 5.0)");
	// testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
	// testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0, 25.0, 5.0)");

	// //4a) Tester funksjonene
	// cout << "Tester funksjoner i oppgave 4:\n";
	// double theta = getUserInputTheta();
	// double absVelocity = getUserInputAbsVelocity();
	// theta = degToRad(theta);
	// vector<double> velocityVector = getVelocityVector(theta, absVelocity);
	// double missedDistance = targetPractice(130.0, velocityVector[0], velocityVector[1]);
	// cout << "Distance from target: " << round(missedDistance) << "m\n";
	//Oppgave 5
	cout << '\n';
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 10; ++i) {
		cout << randomWithLimits(-5, 2) << '\n';
	}
	
	playTargetPractice();

	keep_window_open(); 
}


void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	string answer;
	if (abs(compareOperand - toOperand) <= maxError)
		answer = "does not deviate";
	else answer = "deviates";
	cout << name << " " << answer << '\n';
}
//5

void playTargetPractice() {
    int lowerLimit = 100;
    int upperLimit = 1000;
    int targetDistance = randomWithLimits(lowerLimit, upperLimit);
	double userDistance;
	double flightT;
	cout << "Vekommen til kanonkulespill!\n";
	double userVelocity;
	double userAngle;
	bool victory = false;
	
	for (int i = 0; i < 10; ++i) {
		cout << "Forsøk " << i +1 << '\n';
		cout << "Skriv inn hastighet og vinkel: \n";
		userVelocity = getUserInputAbsVelocity();
		userAngle = getUserInputTheta();
		cout << '\n';
		userAngle = degToRad(userAngle);
		vector<double> velocityVector = getVelocityVector(userAngle, userVelocity);
		cout << '\n';
		flightT = flightTime(userVelocity);
		cout << "Flyvetid: " << round(flightT) << '\n';
		userDistance = targetPractice(targetDistance, velocityVector[0], velocityVector[1]);
		if (userDistance <= 5) {
			victory = true;
			break;
		} else if (i<9) {
			cout << "Du er " << round(userDistance) << " meter unna, prøv igjen!\n";
		}
	}
	if (victory) {
		cout << "Gratulerer!\n";
	} else {
		cout << "Dårlig jobba... avstanden var " << targetDistance << '\n';
	}
	keep_window_open();
}
