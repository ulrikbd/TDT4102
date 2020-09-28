#include "Person.h"

Person::Person(string name, string email, Car *car):
name{name}, email{email}, car{car} {}

string Person::getName() const {return name;}

string Person::getEmail() const {return email;}

void Person::setEmail(string email) {email = email;}

bool Person::hasAvailableSeats() const {
    if (car && car->hasFreeSeat()) return true;
    else return false;
}

void Person::reserveSeat() {
    car->reserveFreeSeat();
}

ostream& operator<<(ostream& os, const Person& p) {
    string n = p.getName();
    string e = p.getEmail();
    string seats;
    if (p.car) {
        bool availSeats = p.hasAvailableSeats();
        if (availSeats) seats = "har ledig sete.";
        else seats = "har ikke ledig sete.";
    } else seats = "har ikke bil.";  
    os << "Navn: " << n << ", email: " << e << ", " << seats;
    return os;
}