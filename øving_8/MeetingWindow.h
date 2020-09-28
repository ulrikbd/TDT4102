#pragma once
#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

constexpr Point topLeft{100, 100};
constexpr int w = 1000;
constexpr int h = 600;
constexpr int fieldPad = w/8;
constexpr int fieldH = h/10;
constexpr int fieldW = w/2;
constexpr int btnW = w/6;
constexpr int btnH = h/7;
constexpr int pad = w/20;

class MeetingWindow: public Window {
    private:
        Button quitBtn;
        In_box personName;
        In_box personEmail;
        Vector_ref<Person> people;
        Button personNewBtn;
    public:
        MeetingWindow(Point xy, int w, int h, const string& title);
        static void cb_quit(Address, Address pw);
        void addPerson();
        static void cb_new_person(Address, Address pw);
        void printPeople();
};