
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	int playerAmt = 2;
	string ans = "";
	do {
		
		Blackjack game{playerAmt};
		game.play();

		cout << "\n\n\nPlay again? y/n\n";
		cin >> ans;
	} while(ans != "n");
	
	return 0;
}

