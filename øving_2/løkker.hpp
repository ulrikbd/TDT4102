#include "std_lib_facilities.h"


void printSum() {
    int number_cap;
    int sum = 0;

    cout << "Hvor mange heltall vil du summere? ";
    cin >> number_cap;

    for (int i = 0; i < number_cap; i++) {
        int temp;
        cout << "Tall: ";
        cin >> temp;
        cout << '\n';
        
        sum += temp;
    }
    cout << "Summen av tallene: " << sum;
}


void whileSum() {
    int sum = 0;
    int temp = 1;

    while (temp != 0) {
        cout << "Skriv 0 for avslutte" << endl;
        cout << "Tall: ";
        cin >> temp;
        cout << '\n';
        
        sum += temp;
    }
    cout << "Summen av tallene: " << sum;
}

double inputDouble() {
	double x;
	cout << "Skriv inn et tall: ";
	cin >> x;

	return x;
}

double nokToEuro() {
    double nok = -1;
    double euro;
    double KURS = 9.75;
    while (nok < 0) {
        cout << "Antall NOK: " << '\n';
        nok = inputDouble();
    }
    euro = nok * KURS;
    return euro;
}