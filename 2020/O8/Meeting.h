#pragma once
#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus{Trondheim, Aalesund, Gjovik};

static map<Campus, string> mapCampusString {
    {Campus::Trondheim, "Trondheim"},
    {Campus::Aalesund, "Ålesund"},
    {Campus::Gjovik, "Gjøvik"}
};


class Meeting {
public:
    Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* p_leader);

    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    const Person* getLeader() const;
    vector<string> getParticipantList() const;

    void addParticipant(const Person* p_person);
    vector<const Person*> findPotentialCoDriving();
    
    ~Meeting();
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;

    const Person* p_leader;
    set<const Person*> participants;

    static set<const Meeting*> meetings;
};

ostream& operator<< (ostream& os, Meeting& m);