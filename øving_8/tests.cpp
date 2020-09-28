#include "tests.h"
#include "std_lib_facilities.h"

void testPerson() {
    cout << "Oppretter person Ulrik med bil\n";
    Car carUlrik{2};
    Person ulrik("Ulrik", "ulrik_bdanielsen@gmail.com", &carUlrik);
    cout << "Operatoren << gir: " << ulrik << '\n';
    cout << "Oppretter person Gjertrud uten bil\n";
    Person gjertrud("Gjertrud", "gjertrud123@yahoo.no");
    cout << "Operatoren << gir: " << gjertrud << '\n';
    cout << "Endrer emailen til Ulrik: ";
    ulrik.setEmail("ulrik.bdanielsen@gmail.com");
    cout << ulrik << '\n';
    cout << "Reserverer begge setene i   Ulriks bil: ";
    ulrik.reserveSeat();
    ulrik.reserveSeat();
    cout << ulrik << '\n';
}

void testMeeting() {
    cout << "Oppretter meeting1 med Ulrik som leder:\n";
    Person ulrik{"Ulrik", "ulrik_danielsen@hotmail.com"};
    Meeting meeting1{17, 15, 16, Campus::Trondheim, "pølsefest", &ulrik};
    cout << meeting1;
    Person gjertrud("Gjertrud", "gjertrud123@yahoo.no");
    cout << "\nLegger til deltageren Gjertrud:\n";
    meeting1.addParticipant(&gjertrud);
    cout << meeting1;
    cout << "\nLager et nytt møte, meeting2:\n";
    Meeting meeting2{18, 14, 16, Campus::Gjøvik, "kosekveld", &gjertrud};
    cout << meeting2;
    cout << "\nOppretter meeting3 med Johhny som leder:\n";
    Person johhny("Johhny", "johnnyboy@msn.no");
    Meeting meeting3(17, 15, 16, Campus::Trondheim, "rakefisklag", &johhny);
    Car stineCar(2);
    Person stine_line("Stine Line", "stin.lin@gmail.com", &stineCar);
    cout << "\nLegger til Stine Line i meeting 3, og kaller findPotentialCoDriving"
    " fra meeting 1\n";
    meeting1.addParticipant(&stine_line);
    vector<const Person*> coDrivers = meeting3.findPotentialCoDriving();
    cout << "Disse personene kan kjøre sammen med deg:\n";
    for (auto p: coDrivers) {
        cout << *p << '\n';
    }
}
