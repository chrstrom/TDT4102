#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

constexpr int strSize{ 4 };
constexpr int letters{ 6 };
bool hasWon{ false };
void checkGuess(string code, string guess, int& numOfCorrectPositions, int& numOfCorrectChars);

void playMastermind() {
	string code, guess;
	int numOfCorrectPositions{ 0 };
	int numOfCorrectChars{ 0 };
	int lives{ 12 };

	//fill "code" with random letters
	code = randomizeString(strSize, 'A', 'A' + (letters - 1));
	cout << "Code: " << code << endl;

	//game loop
	do {
		guess = readInputToString(strSize, 'A', 'A' + (letters - 1));						
		cout << "Guess: " << guess << endl;
	
		//Update game state
		checkGuess(code, guess, numOfCorrectPositions, numOfCorrectChars);
		lives--;
		//Check game state
		if (lives == 0) {
			cout << "You have no lives left! " << endl;
		}
		else if (numOfCorrectPositions == strSize) {
			hasWon = true;
		}
		else {
			cout << "Correct char in correct position: " << numOfCorrectPositions << "\n";
			cout << "Correct char in wrong position: " << numOfCorrectChars << "\n\n";
			cout << lives << " remaining lives!\n" << endl;
		}
	} while (not hasWon && lives > 0);

	//Determine closing message
	if (hasWon) {
		cout << "Congratulations, you won!" << endl;
	}
	else {
		cout << "You lost!" << endl;
	}
}	

void checkGuess(string code, string guess, int& numOfCorrectPositions, int& numOfCorrectChars) {
	int codeFlags[strSize + 1] = { 1, 1, 1, 1 };
	int guessFlags[strSize + 1] = { 1, 1, 1, 1 };

	//Reset refs
	numOfCorrectPositions = 0;
	numOfCorrectChars = 0;
	//test for correct char in the correct position
	for (int idx = 0; idx < strSize; idx++) {
		if (code[idx] == guess[idx]) {
			numOfCorrectPositions++;
			codeFlags[idx] = guessFlags[idx] = 0;
		}
	}
	//test for correct char in wrong position 
	int i, j;
	for (i = 0; i < strSize; i++) {
		for (j = 0; j < strSize; j++) {
			if ((code[i] == guess[j]) && codeFlags[i] && guessFlags[j] && i != j) {
				++numOfCorrectChars;
				codeFlags[i] = 0;
			}
		}
		guessFlags[j] = 0;
	}
}

// A better alternative to checkGuess() is presented below
// Note that you will have to subtract correctColorsAndPos from correctColor to prevent double-counting

int checkCharactersAndPosition(string code, string guess) {
    int count = 0;
    for(int i = 0; i < code.length(); i++) {
        if(guess[i] == code[i]) {
            count++;
        }
    }
    return count;
}

int checkCharacters(string code, string guess) {
    int count = 0;
    for(const char guessChar : guess) {  
        string::iterator iter = find(code, guessChar);   // Iterate through the code, try to find the currect character of guess     
        if(iter != code.end()) {                         // if find() returns code.end(), it did not find the guess char in the code
            count++;
            code.erase(iter);                            // Remove the character that we counted from the code, to prevent double-counting
        }
    }
    return count;
}
