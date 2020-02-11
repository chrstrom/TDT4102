#include "Card.h"

string suitToString(const Suit s) {
    return suitToString_map[s];
}

string rankToString(const Rank r) {
    return rankToString_map[r];
}

string Card::toString() const {
    return rankToString(r) + " of " + suitToString(s);
}

string Card::toStringShort() const {
    return suitToString(s).front() + to_string(static_cast<int>(r) + RANK_BASE_OFFSET);
}