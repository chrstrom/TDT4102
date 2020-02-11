#include "Player.h"

int Player::sumHand() {
    int sum = 0;
    for(int i = 0; i < hand.size(); i++) {
        Rank r = hand[i].getRank();
        int val = rankToInt_map[r];
        
        if(r != Rank::ace || (sum + val < HAND_SUM_MAX)) {
            // Normal case. adding the two leads to no special cases
            sum += val;
        }
        //else if(r == Rank::ace && (sum + val > HAND_SUM_MAX)) {
        else {
            Card temp = hand[i];
            hand[i] = Card{temp.getSuit(), Rank::ace1};
            // Recursively update sum, so to only change one ace at a time when needed  
            sum = sumHand();
        }
    }

    return sum;
}

// Format for print is <PlayerType> <ID>: <Cards> <Sum>
void Player::printHand() {
    if(type == PlayerType::dealer) {
        cout << "Dealer: " << ": ";
    }
    else {
        cout <<  "Player " << ID << ": ";
    }
    
    for(const Card& card : hand) {
        cout << card.toStringShort() << " ";
    }

    cout << "\tSum: " << sumHand() << '\n';
}
