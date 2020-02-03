#pragma once
#include "std_lib_facilities.h"
#include <math.h>

double const acclY();
double const acclX();

double const velY(double initVelY, double time);
double const velX(double initVelX, double time);

double const posX(double initPos, double initVel, double time);
double const posY(double initPos, double initVel, double time);

void const printTime(double time);
double const flightTime(double initVelY);

// Ber brukeren om en vinkel
double getUserInputTheta();

//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity();

// Konverterer fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVel);
double getVelocityY(double theta, double absVel);
double getAbsVelocity(double velX, double velY);

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVel);

double getDistanceTraveled(double initVelX, double initVelY);

double targetPractice(double distanceToTarget, double initVelX, double initVelY);
