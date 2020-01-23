#include "Car.h"

//Oppgave 1c)
bool Car::hasFreeSeats() const { return(freeSeats > 0 ? true : false); }	
void Car::reserveFreeSeat() { --freeSeats; }

