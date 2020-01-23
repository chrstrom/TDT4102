#pragma once

enum class Rank { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, ace1, noRank };
string rankToString(const Rank& rank);
enum class Suit{clubs, diamonds, hearts, spades, noSuit};
string suitToString(const Suit& suit);

static map<Suit, string> SuitToStringMap{
	{Suit::clubs, "Clubs"},
	{Suit::diamonds, "Diamonds"},
	{Suit::hearts, "Hearts"},
	{Suit::spades, "Spades"},
	{Suit::noSuit, "Joker"}
};
static map<Rank, string> RankToStringMap{
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
	{Rank::queen, "Queen" },
	{Rank::king, "King"},
	{Rank::ace, "Ace"},
	{Rank::ace1, "Ace1"},
	{Rank::noRank, "Joker"}
};
/*
struct CardStruct {
	Rank r;
	Suit s;
	
	CardStruct() : r(Rank::ace), s(Suit::spades) {}
};
string toString(const CardStruct& card);
string toStringShort(const CardStruct& card);
*/

class Card {
public:
	friend class CardDeck;
	friend class Blackjack;


	Card() : s(Suit::noSuit), r(Rank::noRank) {};
	Card(Suit suit, Rank rank) {};

	//void getInput();

	string suit(Suit suit) { return suitToString(suit); }
	string rank(Rank rank) { return rankToString(rank); }

	string toString();
	string toStringShort();

	bool isValid();

private:
	Suit s;
	Rank r;
	bool valid;
};

