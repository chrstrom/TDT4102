#include "std_lib_facilities.h"
#include "headers/cannonball.h"
#include "headers/utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

void playTargetPractice() {
	constexpr int targetDistMin = 100;
	constexpr int targetDistMax = 1000;
	constexpr int devMax = 5;
	int lives = 4;

	// Set 2 decimal points for cout
	cout.setf(ios_base::fixed);
	cout.precision(2);

	// Place target randomly between tagetDistMin and targetDistMax
	int targetDist = randomWithLimits(targetDistMax, targetDistMin);

	while(lives) {
		// Get user input
		double theta = degToRad(getUserInputTheta());
		double v = getUserInputAbsVelocity();

		// Calc distances (Intentionally not using targetPractice here)
		double throwDist = getDistanceTraveled(getVelocityX(theta, v), getVelocityY(theta, v));
		double dev = throwDist - targetDist;

		if(abs(dev) < devMax) {
			break; // Win
		}
		else {
			lives--; // Not a winning shot, decrement lives
		}

		// Print info before next try
		cout << "Du kastet " << throwDist << " meter, som er " << abs(dev)
		     << (dev > 0 ? " meter for langt. " : " meter for kort. ")  << "Kula fløy i ";
		printTime(flightTime(getVelocityY(theta, v)));
		cout << '\n' << lives << " liv gjenstår!\n\n";
	}
	
	cout << (lives ? "Gratulerer, du vant!\n" : "Beklager, du tapte!\n");
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	playTargetPractice();
	// // Test for oppg1
	// const int IV_X = 50;
	// const int IV_Y = 25;
	// const int IP = 0;
	// cout << '\t' << "T = 0" << '\t' << "T = 2.5" << '\t' << "T = 5\n";

	// cout << "acclX" << '\t' << acclX() 		 	 << '\t' << acclX() 			<< '\t' << acclX() 		   	   << '\n';
	// cout << "acclY" << '\t' << acclY() 		 	 << '\t' << acclY() 			<< '\t' << acclY() 		   	   << '\n';
	// cout << "velX"  << '\t' << velX(IV_X, 0) 	 << '\t' << velX(IV_X, 2.5) 	<< '\t' << velX(IV_X, 5.0) 	   << '\n';
	// cout << "velY"  << '\t' << velY(IV_Y, 0) 	 << '\t' << velY(IV_Y, 2.5) 	<< '\t' << velY(IV_Y, 5.0) 	   << '\n';
	// cout << "posX"  << '\t' << posX(IP, IV_X, 0)  << '\t' << posX(IP, IV_X, 2.5) << '\t' << posX(IP, IV_X, 5.0) << '\n';
	// cout << "posY"  << '\t' << posY(IP, IV_Y, 0)  << '\t' << posY(IP, IV_Y, 2.5) << '\t' << posY(IP, IV_Y, 5.0) << '\n';

	// testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001, "posX(0.0,50.0,5.0)");
	return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if(abs(compareOperand - toOperand) < maxError) {
		cout << name << ": " << compareOperand << " ~= " << toOperand << '\n';
	}
	else {
		cout << name << ": " << compareOperand << " =/= " << toOperand << '\n';
	}
}