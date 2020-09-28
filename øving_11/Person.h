#pragma once
#include <iostream>
#include <list>

using namespace std;

class Person {
    private:
        string fornavn;
        string etternavn;
    public:
        Person(string fornavn, string etternavn):
        fornavn{fornavn}, etternavn{etternavn} {};
        Person(const Person& p);
        Person& operator=(const Person& a);

        friend ostream& operator<<(ostream& os, const Person& p);

        string getEtternavn() const {return fornavn;};
        string getFornavn() const {return etternavn;}; 
};

void insertOrdered(list<Person>& l, const Person& p);