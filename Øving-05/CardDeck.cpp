#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"
#include <ctime>

//CONSTRUCTOR FOR class CardDeck
CardDeck::CardDeck() {
	constexpr int suitIdxLen{ 4 };
	constexpr int rankIdxLen{ 13 };

	for (int suitIdx = 0; suitIdx < suitIdxLen; suitIdx++) {
		Suit currentSuit{ static_cast<Suit>(suitIdx) };
		for (int rankIdx = 0; rankIdx < rankIdxLen; rankIdx++) {
			Rank currentRank{ static_cast<Rank>(rankIdx) };

			Card currentCard;
			currentCard.s = currentSuit;
			currentCard.r = currentRank;
			cards.push_back(currentCard);
		}
	}
	currentCardIndex = 0;
}

//SHUFFLE FUNCTIONS
void CardDeck::swap(int i, int j) {
	Card temp = cards[i];
	cards[i] = cards[j];
	cards[j] = temp;
}
void CardDeck::shuffle() {
	constexpr int amtOfSwaps{ 1000000 };

	random_device rand;
	mt19937_64 random(rand());
	uniform_int_distribution<> distr(0, cards.size() - 1);

	clock_t time;
	time = clock();

	cout << "Shuffling deck." << endl;
	for (int i = 0; i < amtOfSwaps; i++) {
		int m{ distr(random) };
		int n{ distr(random) };

		if (m != n) {
			swap(m, n);
		}
	}
	time = clock() - time;
	cout << "Time to shuffle by swapping " << amtOfSwaps << " times: " << time << "ms."<< endl;
}

//PRINT FUNCTIONS
void CardDeck::print() {
	for (Card card : cards) {
		cout << card.toString() << endl;
	}
}
void CardDeck::printShort() {
	for (Card card : cards) {
		cout << card.toStringShort() << "  ";
	}
	cout << endl;
}

//DRAWING CARDS
const Card& CardDeck::drawCard() {
	const Card& drawnCard{ cards[currentCardIndex] };
	currentCardIndex += 1;
	return drawnCard;
}
