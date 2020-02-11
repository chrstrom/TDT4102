#pragma once

#include "std_lib_facilities.h"
#include "Card.h"

constexpr int HAND_SUM_MAX = 21;
constexpr int DEALER_HAND_SUM_HOLD = 17;

enum class PlayerType{dealer, player};

class Player {
public:
    friend class Blackjack;
    
    Player(PlayerType type, string ID) : type{type}, ID{ID} {};

    string getID() { return ID; };
    int sumHand();
    void printHand();

private:
    PlayerType type;
    string ID;
    vector<Card> hand;
};



