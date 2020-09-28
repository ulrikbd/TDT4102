#pragma once
#include "Person.h"
#include "std_lib_facilities.h"

enum class Campus { Trondheim, Ålesund, Gjøvik };

ostream& operator<<(ostream& os, const Campus campus);

class Meeting {
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const Person* leader;
        set<const Person*> participants;
        static set<const Meeting*> meetings;
    public:
        Meeting(int day, int startTime, int endTime, Campus location,
        string subject, const Person* leader);
        int getDay() const {return day;};
        int getStartTime() const {return startTime;};
        int getEndTime() const {return endTime;};
        Campus getLocation() const {return location;};
        string getSubject() const {return subject;};
        const Person* getLeader() const {return leader;};
        void addParticipant(const Person* p) {participants.insert(p);};
        set<const Person*> getParticipantsList() const {return participants;};
        set<const Meeting*> getMeetingsList() const {return meetings;};
        vector<const Person*> findPotentialCoDriving();
        ~Meeting();
};

ostream& operator<<(ostream& os, const Meeting meeting);