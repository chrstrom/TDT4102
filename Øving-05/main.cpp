#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"


int main(){
	//CardStruct cardFromStruct;
	//Card.getInput();

	CardDeck cardDeck;
	int choice{ -1 };
	while (choice != 0) {
		
		cout << "Meny: \n"
			 << "1: suitToString();\n"
			 << "2: rankToString();\n"
			 << "3: toString();\n"
			 << "4: toStringShort();\n"
			 << "5: class CardDeck tests\n"
			 << "6: Play blackjack:\n"
			 << "0: Avslutt\n";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << suitToString(Suit::spades) << endl;
			break;
		case 2: 
			cout << rankToString(Rank::ace) << endl;
			break;
		/*case 3:
			cout << toString(cardFromStruct) << endl;
			break;
		case 4:
			cout << toStringShort(cardFromStruct) << endl;
			break;*/
		/*case 5:
			cout << "Unshuffled deck: " << endl;
			Deck.printShort();
			Deck.shuffle();
			cout << endl;
			//Deck.print();
			cout << endl;
			cout << "Shuffled deck: " << endl;
			Deck.printShort();*/
		case 6:
			cardDeck.print();
			blackjack.playBlackjack();
			break;
		case 0:
			cout << "Avslutter..." << endl;
			break;
		default:
			cout << "Ugyldig menyvalg." << endl;
		}
	}
	return 0;
}