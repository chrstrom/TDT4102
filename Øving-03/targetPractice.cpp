#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "targetPractice.h"

void playTargetPractice() {
	int lives{ 10 };
	double theta;
	double velocityX, velocityY, absVelocity;
	double distanceTraveled, time, distanceToTarget;
	constexpr int maxError{ 5 };

	//Generate random target location
	const int randomTarget = randomWithLimits(100, 1000);

	while (lives != 0) {
	//update velocities Vx and Vy with values from user input
		getUserInput(theta, absVelocity);	
		theta = degToRad(theta);
		getVelocityVector(theta, absVelocity, velocityX, velocityY);

	//distance traveled by cannon ball and distance to target						//velger å ikke bruke targetPractice()
		distanceTraveled = getDistanceTraveled(velocityX, velocityY);
		distanceToTarget = randomTarget - distanceTraveled;

	//print information about shot
		if (distanceToTarget > 0) {
			cout << "\nThe cannon ball landed " << abs(distanceToTarget) << " meters short of the target.\n";
		}
		else {
			cout << "\nThe cannon ball landed " << abs(distanceToTarget) << " meters past the target.\n";
		}
	//find flight time and print
		time = flightTime(velocityY);
		cout << "The cannon ball landed after ";
		printTime(time);

	//check for game state
		if (abs(distanceToTarget) < maxError) {
			cout << "Congratulations, you won!" << endl;
			break;
		}
		else {
			--lives;
			cout << '\n'<< lives << " lives remaining!\n";
			if (lives == 0) {
				cout << "You lost the game!\n\n";
			}
			else {
				cout << "Try again!\n\n";
			}
		}
	}
}
