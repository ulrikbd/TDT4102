#include "Animal.h"


Animal::Animal(string name, int age): 
name{name}, age{age} {}

string Animal::toString() {
    string s = "Animal: " + name + ", " + to_string(age);
    return s;
}


string Dog::toString() {
    string s = "Dog: " + name + ", " + to_string(age);
    return s;
}

string Cat::toString() {
    string s = "Cat: " + name + ", " + to_string(age);
    return s;
}
