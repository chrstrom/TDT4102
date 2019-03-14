#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

int randomWithLimits(int min, int max) {
	int random_num = rand();
	random_num = random_num % (max - min + 1) + min;

	return random_num;
}