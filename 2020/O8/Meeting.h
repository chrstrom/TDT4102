#pragma once
#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus{Trodheim, Aalesund, Gjovik};

class Meeting {
public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    const Person* getLeader() const;

private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
};