#pragma once

class CardDeck {
public:
	friend class Blackjack;
	CardDeck();

	void print();
	void printShort();

	void shuffle();

	const Card& drawCard();
private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int i, int j);	//velger å legge denne i private, siden den kun opererer innad CardDeck, så ingen grunn til at den skal være public
};
