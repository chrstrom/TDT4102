#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Player.h"

enum class TurnState{prompt, drawing, turnEnd, invalid};

class Blackjack {
public:
    Blackjack(int playerAmt);
    void play();

private:
    CardDeck deck;
    Player dealer;
    vector<Player> players;

    void init();
    void playDealer();
    
    string drawCardPromt();

    void printTable();  
    void printResults();

   
};