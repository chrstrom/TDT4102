#include "std_lib_facilities.h"

#include "headers/utilities.h"
#include "headers/tests.h"
#include "headers/mastermind.h"
#include "headers/mastermindGraphics.h"


int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	playMastermind();
	return 0;
}
