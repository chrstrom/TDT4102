#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "targetPractice.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void testInput();
void testRand();

int main() {
	setlocale(LC_ALL, "Norwegian");
	srand(static_cast<unsigned int>(time(nullptr)));

	playTargetPractice();

	cout << endl;
	testDeviation(posX(0.0, 50.0, 5.0), 250.0, 0.0001,		"posX(0.0, 50.0, 5.0)");
	testDeviation(posY(0.0, 25, 2.5), 31.84, 0.0001,		"posY(0.0, 50.0, 2.5)");
	testDeviation(velY(25.0, 5.0), -24.05, 0.0001,			"velY(25.0, 5.0)");
	cout << endl;

	testInput();						

	for (int i = 0; i < 5; i++) {
		testRand();
	}
	
	return 0;
}


//3b
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(4);

	double absDiff = abs(compareOperand - toOperand);
	
	cout << "For " << name << ':' << endl;
	if (absDiff < maxError) {
		cout << compareOperand << " og " << toOperand << " er like, innenfor feilmarginen" << endl;
	}
	else {
		cout << compareOperand << " og " << toOperand << " er ulike mhp feilmarginen. "<< endl;
	}
}

//4e
void testInput() {
	double theta{ 0 };
	double absVelocity{ 0 }, velocityX{ 0 }, velocityY{ 0 };

	getUserInput(theta, absVelocity);
	cout << "Theta(deg): " << theta << endl;
	cout << "Theta(rad): " << degToRad(theta) << endl;
	cout << "Velocity(m/s): " << absVelocity << endl;
	theta = degToRad(theta);

	getVelocityVector(theta, absVelocity, velocityX, velocityY);

	targetPractice(120, velocityX, velocityY);

}

//5b
void testRand() {
	vector<int> randIntVector;
	int randomInt, minLimit{ 0 }, maxLimit{ 100 };

	for (int i = 0; i < 10; i++) {
		randomInt = randomWithLimits(minLimit, maxLimit);
		randIntVector.push_back(randomInt);
	}

	cout << "10 random numbers between " << minLimit << " and " << maxLimit << ": [ ";
	for (int element : randIntVector) {
		cout << element << ' ';
	}
	cout << ']' << endl;

}
