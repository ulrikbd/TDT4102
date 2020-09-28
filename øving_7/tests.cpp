#include "tests.h"

void testAnimal() {
    Vector_ref<Animal> animals;
    Animal lars("Lars", 3);
    animals.push_back(lars);
    Cat felix("Felix", 16);
    animals.push_back(felix); 
    Dog edmund("Edmund", 7);
    animals.push_back(edmund);

    for (int i = 0; i < animals.size(); ++i) {
        cout << animals[i].toString() << endl;
    }
}