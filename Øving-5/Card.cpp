#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"

//Oppgave 1

////e) Teori.
//"I denne oppgaven har vi valgt å represenetere farge og verdi på kort som symboler. Nevn
//to fordeler ved å bruke symboler framfor f.eks.heltall og strenger i koden."

//Fordel 1: Bedre lesbarhet => Færre menneskelige feil

//Fordel 2: 


string suitToString(const Suit& suit) {
	return SuitToStringMap[suit];
}

string rankToString(const Rank& rank) {
	return RankToStringMap[rank];
}

/*
Oppgave 2
string toString(const CardStruct& card) {
	return{ rankToString(card.r) + " of " + suitToString(card.s) };
}
string toStringShort(const CardStruct& card) {
	string suitShort{ suitToString(card.s).front() };
	string rankShort{ to_string(static_cast<int>(card.r) + 2) };	//+2 siden enum Rank starter med "two" i idx 0; 
	
	return suitShort + rankShort;
}
*/

bool Card::isValid() {
	if (s == Suit::noSuit || r == Rank::noRank) {
		return false;
	}
	else {
		return true;
	}
}

string Card::toString() {
	if (isValid()) {
		return rankToString(r) + " of " + suitToString(s);
	}
	else {
		return "Ugyldig kort";
	}
}

string Card::toStringShort() {
	if (isValid()) {
		string suitShort{ "" };
		suitShort.push_back(toupper(suitToString(s).front()));
		string rankShort{ to_string(static_cast<int>(r) + 2) };	//+2 siden enum Rank starter med "two" i idx 0; 

		return suitShort + rankShort;
	}
	else {
		return "Ugyldig kort";
	}
}


/*Refleksjonsoppgave:
Et kort vil være et av 52 i kortstokken, og det er derfor logisk å bruke class. Struct brukes hovedsaklig der
variablene kan ta en hvilken som helst verdi.

Klassens invariant er suit og rank: et kort kan være et av de 52 kortene i kortstokken, men ikke noe annet
utover det. Med en struct har vi ikke like mye kontroll på valid states, så det er foretrukket å bruke class.*/
