#include "Meeting.h"

set<const Meeting*> Meeting::meetings;

ostream& operator<< (ostream& os, Meeting& m) {
     os << "Subject: "   <<   m.getSubject()                   << '\n'
        << "Location: "  <<   mapCampusString[m.getLocation()] << '\n'
        << "Starts at: " <<   m.getStartTime()                 << '\n'
        << "Ends at: "   <<   m.getEndTime()                   << '\n'
        << "Leader: "    <<   m.getLeader()->getName()         << '\n';

    os  << "Participants: " << '\n';
    for(const auto& participant : m.getParticipantList()) {
        os << participant << '\n';
    }

    return os;
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* p_leader)
                : day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, p_leader{p_leader}
{
    meetings.insert(this);
    addParticipant(p_leader);
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
// Skriv funksjonen findPotentialCoDriving.
// Dette skal vere ein medlemsfunksjon i Meeting. Funksjonen skal ikkje ta inn noko, og skal
// returnere ei liste med Person-peikarar til personar som har ledige seter i bilen til andre
// møte på same stad, på same dag og med både start-tid og slutt-tid som er mindre eller lik
// ein time i skilnad.
// Hint: Funksjonen vil ha følgjande

vector<const Person*> Meeting::findPotentialCoDriving() {

    vector<const Person*> coDrivers;

    for(const auto& m : meetings) {
        if(m != this && m->getLeader()->hasAvailableSeats() &&
            m->location == this->location && m->day == this->day) &&
            (abs(m->startTime - this->startTime) <= 1) && (abs(m->endTime - this->endTime)) )
        {
            coDrivers.push_back(m->getLeader());
        }
    }
    return coDrivers;
}