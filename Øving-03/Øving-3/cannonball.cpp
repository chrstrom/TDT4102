#define _USE_MATH_DEFINES
#include "cannonball.h"
#include "std_lib_facilities.h"
#include <math.h>


	//DEL 1

//a
double acclY() {
	constexpr double acclY = -9.81;
	return acclY;
}

//b
double velY(double initVelocityY, double time) {
	double velY = initVelocityY + acclY()*time;
	return velY;
}

//c
double posX(double initPosition, double initVelocity, double time) {
	double posX = initPosition + initVelocity * time;
	return posX;
}

double posY(double initPosition, double initVelocity, double time) {
	double posY;
	posY = initPosition + initVelocity * time + (acclY()*time*time)/2.0;
	return posY;
}

//d
void printTime(double time) {
	const int secInHrs = 3600;
	const int minInHrs = 60;
	int hrs, min;
	int sec = time;

	hrs = sec / secInHrs;
	min = (sec % secInHrs) / minInHrs;
	sec = (sec % secInHrs) % minInHrs;

	cout << hrs << " hours, "
		 << min << " minutes, "
		 << sec << " seconds\n";
}

//e
double flightTime(double initVelocityY) {
	double flightTime;
	flightTime = (-2 * initVelocityY) / acclY();
	return flightTime;
}

	//DEL 3
//a
void getUserInput(double& theta, double& absVelocity) {
	
	cout << "Input angle (in deg): " << endl;
	cin >> theta;
	cout << "Input velocity (in m/s): " << endl;
	cin >> absVelocity;

	}

double degToRad(double deg) {
	double rad;

	rad = deg * M_PI / 180;
	return rad;
	}

//VELOCITY Vx, Vy, V
double getVelocityX(double theta, double absVelocity) {
	double velocityX{ absVelocity*cos(theta) };
	return velocityX;
}
double getVelocityY(double theta, double absVelocity) {
	double velocityY{ absVelocity*sin(theta) };
	return velocityY;
}
void getVelocityVector(double theta, double absVelocity,
	double& velocityX, double& velocityY) {
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}

//b
double getDistanceTraveled(double velocityX, double velocityY) {
	double time{ flightTime(velocityY) };
	double distanceTraveled{ posX(0, velocityX, time) };
	return distanceTraveled;
}

//c

//find |target - position| 
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	double deviation, distanceTraveled;

	distanceTraveled = getDistanceTraveled(velocityX, velocityY);
	deviation = distanceToTarget - distanceTraveled;
	cout << "Distance traveled: " << distanceTraveled << endl;
	cout << "Deviation: " << deviation << endl;
	return deviation;
}

