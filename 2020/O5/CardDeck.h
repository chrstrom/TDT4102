#pragma once
#include "std_lib_facilities.h"
#include "Card.h"


class CardDeck {
public:
    CardDeck();

    void print() const;
    void printShort() const;
    void shuffle();
    const Card drawCard();

private:
    vector<Card> cards;
    void swap(int i, int j);
};