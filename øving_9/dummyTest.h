#pragma once
#include <iostream>
#include <utility>

using namespace std;

class Dummy {
    public:
        int *num;
        Dummy() {
        num = new int{0};
        }

        Dummy(const Dummy &other): num{nullptr} {
            this->num = new int{};
            *num = *other.num;
        }

        Dummy& operator=(Dummy rhs) {
            swap(num, rhs.num);
            return *this;
        }

        ~Dummy() {
        delete num;
    }
};

void dummyTest();