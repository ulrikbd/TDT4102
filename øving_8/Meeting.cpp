#include "Meeting.h"

ostream& operator<<(ostream& os, const Campus campus) {
    switch(campus) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case Campus::Ålesund:
            os << "Ålesund";
            break;
        case Campus::Gjøvik:
            os << "Gjøvik";
            break;
    }
    return os;
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, 
string subject, const Person* leader):
day{day}, startTime{startTime}, endTime{endTime}, location{location},
subject{subject}, leader{leader} {
    participants.insert(leader);
    meetings.insert(this);
}

Meeting::~Meeting() {
    meetings.erase(this);
}

set<const Meeting*> Meeting::meetings;


ostream& operator<<(ostream& os, const Meeting meeting) {
    os << "Subject: " << meeting.getSubject() << '\n';
    os << "Location: " << meeting.getLocation() << '\n';
    os << "Starttime: " << meeting.getStartTime() << '\n';
    os << "Endtime: " << meeting.getEndTime() << '\n';
    os << "Leader: " << meeting.getLeader()->getName() << '\n';
    cout << "Participants:\n";
    for (auto p: meeting.getParticipantsList()) {
        cout << *p << '\n';
    }
    return os;
}

vector<const Person*> Meeting::findPotentialCoDriving() {
    vector<const Person*> potentialCoDrivers;
    set<const Person*> participants;
    set<const Meeting*> meetings = getMeetingsList();
    int day = getDay();
    int startTime = getStartTime();
    int endTime = getEndTime();
    Campus location = getLocation();
    for (auto meeting: meetings) {
        if (meeting != this && meeting->getDay() == day &&
         abs(startTime - meeting->getStartTime()) < 1 &&
          abs(endTime - meeting->getEndTime()) < 1 &&
          location == meeting->getLocation()) {
            participants = meeting->getParticipantsList();
            for (auto participant: participants) {
                if (participant->hasAvailableSeats()) {
                    potentialCoDrivers.push_back(participant);
                }
            }
        }
    }
    return potentialCoDrivers;
}
