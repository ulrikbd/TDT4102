#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title):
Window{xy, w, h, title}, quitBtn{Button(Point{x_max()-pad-btnW, xy.y + pad}, btnW, btnH, "quit", cb_quit)},
personName{Point{xy.x, xy.y + pad}, fieldW, fieldH, "Name"},
personEmail{Point{xy.x, xy.y + 2*pad + fieldH}, fieldW, fieldH, "Email"},
personNewBtn{Button{Point{xy.x, xy.y + 3*pad + 2*fieldH}, btnW, btnH, "addPerson", cb_new_person}}
{
    attach(quitBtn);
    attach(personName);
    attach(personEmail);
    attach(personNewBtn);
}

void MeetingWindow::cb_quit(Address, Address pw) {
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::addPerson() {
    string name = personName.get_string();
    string email = personEmail.get_string();
    if (!name.empty() && !email.empty()) {
        people.push_back(new Person{name, email});
    }
    personName.clear_value();
    personEmail.clear_value();
}

void MeetingWindow::cb_new_person(Address, Address pw) {
    reference_to<MeetingWindow>(pw).addPerson();
}

void MeetingWindow::printPeople() {
    for (auto p: people) {
        cout << *p << '\n';
    }
}