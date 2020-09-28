#include "std_lib_facilities.h"
#include "løkker.hpp"
#include "menysystem.hpp"
#include "funksjoner.hpp"
#include "pythagoras.hpp"
#include "lån.hpp"


//Input
void inputAndPrintInteger() {
	int x;
	cout << "Skriv inn et tall: ";
	cin >> x;

	cout << "Du skrev: " << x;
}

int inputInteger() {
	int x;
	cout << "Skriv inn et tall: ";
	cin >> x;

	return x;
}

void inputIntegerAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();
	int sum = x + y;
	cout << "Summen av tallene: " << sum;
}

bool isOdd(int n) {
	if (n % 2 == 0) {
		return false;
	} else {
		return true;
	}
}

void printHumanReadableTime(int seconds) {
	int hours, minutes;

	hours = seconds / 3600;
	seconds -= hours * 3600;

	minutes = seconds / 60;
	seconds -= minutes * 60;

	cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder.";
}


int main() {
	// // Input
	// //Oppgave a)
	// cout << "Oppgave a)" << '\n';
	// inputAndPrintInteger();
	// cout << '\n';
	// //Oppgave b)
	// cout << "Oppgave b)" << '\n';
	// int number = inputInteger();
	// cout << "Du skrev: " << number << '\n';
	// //Oppgave c)
	// cout << "Oppgave c)" << '\n';
	// inputIntegerAndPrintSum();
	// cout  << '\n';
	// //Oppgave d) Trenger returnverdien
	// //Oppgave e)
	// string	parity;
	// for (int x = 0; x < 16; x++) {
	// 	if (isOdd(x)) {
	// 		parity = "odde";
	// 	} else {
	// 		parity = "partall";
	// 	}
	// 	cout << x << " er " << parity << '\n';
	// }
	// // Oppgave f)
	// printHumanReadableTime(10000);

	// //Løkker
	// printSum();
	// cout << '\n';
	// //Oppgave b)
	// cout << "Oppgave b)" << '\n';
	// whileSum();
	// cout << '\n';
	// //Oppgave c) Trivielt
	// // Oppgave d) inputDouble()
	// cout << "Oppgave d)" << '\n';
	// cout << inputDouble() << '\n';
	// //Oppgave e)
	// cout << "Oppgave e)" << '\n';
	// cout << setprecision(2) << fixed << nokToEuro() << '\n';
	// // Oppgave f)
	// /*Menes det i oppgave e)? Trenger åpenbart desimaltall i 
	// oppgave e)m bruker derfor doubles*/

	//Menyssystem
	int temp = 4;
	while (temp != 0) {
		cout << "Velg funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO" << endl;
		cout << "4) Gangetabellen" << endl;
		cout << "5) Løs andregrafsligning" << endl;
		cout << "6) Annuitet versus serielån" << endl;
		cout << "Valg: ";
		cin >> temp;

		if (temp == 1) {
			inputIntegerAndPrintSum();
		} else if (temp == 2) {
			printSum();
		} else if (temp ==3) {
			nokToEuro();
		} else if (temp == 4) {
			multiplicationTable();
		} else if (temp == 5) {
			solveQuadraticEquation();
		} else if (temp == 6) {
			loanDifference();
		}
		cout << endl;
	}

	// Pythagoras
	pythagoras();


	// //Lån med løkker
	// //Oppgave a)
	// cout << "Oppgave a)" << endl;
	// calculateSeries(10000, 5, 10);
	// //Oppgave b)
	// cout << "Oppgave b)" << endl;
	// calculateAnnuity(10000, 5, 10);
	// cout << endl;
	// loanDifference();

    return 0;
}
