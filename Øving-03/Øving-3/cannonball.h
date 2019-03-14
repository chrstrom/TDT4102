#pragma once
#include "std_lib_facilities.h"

	//DEL 1

//a
double acclY();

//b
double velY(double initVelocityY, double time);

//c
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

//d
void printTime(double time);

//e
double flightTime(double initVelocityY);

//f
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

	//DEL 2

//a
void getUserInput(double& theta, double& absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity,
						double& velocityX, double&velocityY);

double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);