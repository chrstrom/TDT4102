#pragma once
#include "std_lib_facilities.h"

constexpr int SUIT_COUNT = 4;
constexpr int RANK_COUNT = 13;
constexpr int RANK_BASE_OFFSET = 2;

enum class Suit{clubs, diamonds, hearts, spades};
enum class Rank{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, ace1};

static map<Suit, string> suitToString_map{
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};

static map<Rank, string> rankToString_map{
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
    {Rank::ace1, "Ace1"}
};

static map<Rank, int> rankToInt_map{
    {Rank::ace1, 1},
    {Rank::two, 2},
    {Rank::three, 3},
    {Rank::four, 4},
    {Rank::five, 5},
    {Rank::six, 6},
    {Rank::seven, 7},
    {Rank::eight, 8},
    {Rank::nine, 9},
    {Rank::ten, 10},
    {Rank::jack, 10},
    {Rank::queen, 10},
    {Rank::king, 10},
    {Rank::ace, 11}
};

string suitToString(const Suit s);
string rankToString(const Rank r);


class Card {
public:
    Card(Suit suit, Rank rank) : s{suit}, r{rank} {};

    Suit getSuit() const { return s; };
    Rank getRank() const { return r; };

    string toString() const;
    string toStringShort() const;
    
private:
    Suit s;
    Rank r;
};
