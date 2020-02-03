#include "headers/cannonball.h"

double const acclY() {
    return -9.81;
}
double const acclX() {
    return 0;
}

double const velY(double initVelY, double time) {
    return initVelY + acclY()*time;
 }
double const velX(double initVelX, double time) {
    return initVelX + acclX()*time;
}

double const posX(double initPos, double initVel, double time) {
    return initPos + initVel*time + 0.5*acclX()*time*time;
}
double const posY(double initPos, double initVel, double time) {
    return initPos + initVel*time + 0.5*acclY()*time*time;
}

void const printTime(double time) {
    constexpr int S_IN_H = 3600;
	constexpr int M_IN_H = 60;
    
	int hr = static_cast<int>(time) / S_IN_H;						
	int min = (static_cast<int>(time) % S_IN_H) / M_IN_H;			
	int sec = (static_cast<int>(time) % S_IN_H) % M_IN_H;

    if( !hr && !min) {
        cout << sec << " sekunder.\n";
    }
    else if(!hr && min) {
        cout << min <<" minutter og " << sec << " sekunder.\n";

    } else {
        cout << hr << " timer, " << min << " minutter og " << sec << " sekunder.\n";
    } 
}
double const flightTime(double initVelY) {
    return -2*initVelY/acclY();
}

double getUserInputTheta() {
    double theta;
    cout << "Theta [deg]: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    double v;
    cout << "|v| [m/s]: ";
    cin >> v;
    return v;
}


double degToRad(double deg) {
    return M_PI * deg / 180;
}

double getVelocityX(double theta, double absVel) {
    return absVel * cos(theta);
}

double getVelocityY(double theta, double absVel) {
    return absVel * sin(theta);
}

double getAbsVelocity(double velX, double velY) {
    return sqrt(velX*velX + velY*velY);
}

vector<double> getVelocityVector(double theta, double absVel) {
    return {getVelocityX(theta, absVel), getVelocityY(theta, absVel)};
}

double getDistanceTraveled(double initVelX, double initVelY) {
    return posX(0, initVelX, flightTime(initVelY));
}

double targetPractice(double distanceToTarget, double initVelX, double initVelY) {
    return getDistanceTraveled(initVelX, initVelY) - distanceToTarget;
}