#include "CardDeck.h"

CardDeck::CardDeck() {
    for(int suit = 0; suit < SUIT_COUNT; suit++) {
        for(int rank = 0; rank < RANK_COUNT; rank++) {
            cards.push_back(Card{Suit{suit}, Rank{rank}});
        }
    }
}

void CardDeck::swap(int i, int j) {
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

void CardDeck::print() const {
    for(const Card& card : cards) {
        cout << card.toString() << '\n';
    }
}

void CardDeck::printShort() const {
    for(const Card& card : cards) {
        cout << card.toStringShort() << '\n';
    }
}

void CardDeck::shuffle() {
    constexpr int SWAP_AMT = 10000;
    cout << "\n\nShuffling deck...\n";

    for(int i = 0; i < SWAP_AMT; i++) {
        int r1 = rand() % (SUIT_COUNT * RANK_COUNT);
        int r2 = rand() % (SUIT_COUNT * RANK_COUNT);

        if(r1 != r2) {
            swap(r1, r2);
        }
        else {
            i--;
        }
    }
    cout << "Shuffle complete!\n\n\n";
}

const Card CardDeck::drawCard() {
    Card c = cards.front();
    cards.erase(cards.begin());
    return c;
}