#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person {
    private:
        string name;
        string email;
        Car *car;
    public:
        Person(string name, string email, Car *car = nullptr);
        friend ostream& operator<<(ostream& os, const Person& p);
        string getName() const;
        string getEmail() const;
        void setEmail(string email);
        bool hasAvailableSeats() const;
        void reserveSeat();
};
