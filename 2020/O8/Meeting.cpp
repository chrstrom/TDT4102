#include "Meeting.h"

set<const Meeting*> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* p_leader)
                : day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, p_leader{p_leader}
{
    addParticipant(p_leader);
    meetings.insert(this);
    
}

Meeting::~Meeting() {
    meetings.erase(this);
}

int Meeting::getDay() const {
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

Campus Meeting::getLocation() const {
    return location;
}

string Meeting::getSubject() const {
    return subject;
}

const Person* Meeting::getLeader() const {
    return p_leader;
}

void Meeting::addParticipant(const Person* p_person) {
    participants.insert(p_person);
}

vector<string> Meeting::getParticipantList() const{
    vector<string> names;
    for(const auto& person : participants) {
        names.push_back(person->getName());
    }
    return names;
}

// Overlast operator<< for Meeting.
// Denne operatoren skal IKKJE vere ein friend av Meeting. Du står fritt til å velje for-
// mat sjølv, men du skal skrive ut subject, location, startTime, endTime, og namnet på
// møteleiaren. I tillegg skal han skrive ut ei liste med namna på alle deltakaran

ostream& operator<< (ostream& os, Meeting& m) {
    return os << "Subject: "   <<   m.getSubject()                   << '\n'
              << "Location: "  <<   mapCampusString[m.getLocation()] << '\n'
              << "Starts at: " <<   m.getStartTime()                 << '\n'
              << "Ends at: "   <<   m.getEndTime()                   << '\n'
              << "Leader: "    <<   m.getLeader()->getName()         << '\n';
}