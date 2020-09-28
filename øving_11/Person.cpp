#include "Person.h"

Person::Person(const Person& p): fornavn{p.fornavn}, etternavn{p.etternavn}
{}

Person& Person::operator=(const Person& p) {
    fornavn = p.fornavn;
    etternavn = p.etternavn;
    return *this;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.fornavn << " " << p.etternavn;
    return os;
}

void insertOrdered(list<Person>& l, const Person& p) {
    list<Person>::iterator i{l.begin()};
    while ((i->getEtternavn()) < p.getEtternavn() && i != l.end()) {
        i++;
    }
    i = l.insert(i, p);
}