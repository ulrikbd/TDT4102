#pragma once
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr int screenWidth = 1000;
constexpr int screenHeight = 600;

constexpr double vehicleRadius = 15;

constexpr double goalRadius = 30;

constexpr double spillRadius = 20;
constexpr double boostRadius = 10;
constexpr double peelRadius = 5;


class PhysicsState
{
public:
	double x, y, angle, speed = 0, grip = 1;

	void update(double translationAcceleration, double angularAcceleration)
	{
		// Desse skal vere i intervallet [-1,1]
		translationAcceleration = std::max(-1.0, std::min(1.0, translationAcceleration));
		angularAcceleration = std::max(-1.0, std::min(1.0, angularAcceleration));

		grip += 0.01 * (1 - grip);
		speed += 0.006 * grip * translationAcceleration * (6 - abs(speed));

		if ((speed > 0) != (translationAcceleration > 0)) // Bremsing
			speed += 0.03 * grip * translationAcceleration;

		angle += 0.03 * grip * angularAcceleration;
		x += speed * cos(angle);
		y += speed * sin(angle);
	}

	void slide(double slideAngle)
	{
		grip += 0.01 * (1 - grip);
		speed -= 0.036 * grip * speed;

		angle += 0.12 * grip;
		x += speed * cos(slideAngle);
		y += speed * sin(slideAngle);

	}
};
/*Denne funksjonen er static fordi vi vil definere den i header-file, 
og dermed slippe å ha en tilhorende cpp-fil. Dette har vi gjort for å ikke ha så mye utdelt kode.
 Dette er egentlig ikke god kodepraksis. Dette er IKKE en del av pensum.*/
static double angleBetween(std::pair<double, double> vec1,
	std::pair<double, double> vec2)
	// Returnerer vinkel mellom to vektorar i radianar.
{
	double dot = vec1.first * vec2.first + vec1.second * vec2.second;
	double det = vec1.first * vec2.second - vec1.second * vec2.first;
	return atan2(det, dot);
}