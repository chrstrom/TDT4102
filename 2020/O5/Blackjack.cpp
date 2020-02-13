#include "Blackjack.h"

Blackjack::Blackjack(int playerAmt) : dealer{Player{PlayerType::dealer, to_string(0)}} {
    for(int i = 0; i < playerAmt; i++) {
        players.push_back(Player{PlayerType::player, to_string(i+1)});
    }

    deck.shuffle();
}

void Blackjack::play() {
    init();

    for(Player& player : players) {
        bool turnEnd = false;   // Turn should end if sum of hand > 21, or if the player asks to end

        while(!turnEnd) {
            player.printHand();
            
            if(player.sumHand() == HAND_SUM_MAX && player.hand.size() == 2) {
                cout << "BLACKJACK!\n";
                turnEnd = true;
            }
            else {
                string ans = drawCardPromt();

                if (ans == "y") {
                    player.hand.push_back(deck.drawCard());

                    if(player.sumHand() > HAND_SUM_MAX) {
                        player.printHand();
                        cout << "BUST!\n\n";
                        turnEnd = true;
                    }
                }
                else if (ans == "n") {
                    turnEnd = true;
                }
                else {
                    __throw_logic_error("ans != 'y' || 'n'");
                }
            }
        }
    }// End for-loop for all players' turn

    playDealer();
    printResults();
}


void Blackjack::init() {
    // Card handout: players face up, dealer face up, players face up, dealer face down
    for(Player& player : players) {
        player.hand.push_back(deck.drawCard());
    }

    dealer.hand.push_back(deck.drawCard());

     for(Player& player : players) {
        player.hand.push_back(deck.drawCard());
    }

    dealer.hand.push_back(deck.drawCard());

    cout << "\nDealer's hand: " << dealer.hand[0].toStringShort() << " **\n"; 
    
}

string Blackjack::drawCardPromt() {
        string s = "x";
    
    while(1) {
        cout << "\nDraw card? y/n: ";

        cin >> s;

        if(s == "y" || s == "n") {
            break;
        }
        else {
            cout << "\nChoice must be y/n !!\n";
        }
    }

    return s;
}

void Blackjack::printTable() {
    for(Player& player : players) {
        player.printHand();
        cout << "\n\n";
    }
}

void Blackjack::printResults() {
    dealer.printHand();
    
    cout << "\n\n";
    
    for(Player& player : players) {
        if(player.sumHand() > dealer.sumHand() && player.sumHand() <= HAND_SUM_MAX) {
            cout << "Player " << player.getID() << " won!\n";
        }
        else {
            cout << "Player " << player.getID() << " lost!\n";
        }
    }
}

void Blackjack::playDealer() {
    while(1) {
        if(dealer.sumHand() >= DEALER_HAND_SUM_HOLD) {
            break;
        }
        else {
            dealer.hand.push_back(deck.drawCard());
        }
    }
}


// The game logic could also be implemented using an FSM, potentially allowing greater modularity and readability
// TurnState state = TurnState::prompt;
// // Turn should always end on "hold"
// while(state != TurnState::turnEnd) {
//     switch(state) {
//         case TurnState::prompt: {

//             cout << "\nPlayer " + to_string(counter) + " : ";
//             player.printHand();

//             string ans = drawCardPromt();
            

//             if (ans == "y") {
//                 state = TurnState::drawing;
//             }
//             else if (ans == "n") {
//                 state = TurnState::turnEnd;
//             }
//             else {
//                 state = TurnState::invalid;
//             }

//             break;
//         }
        
//         case TurnState::drawing: {
//             player.hand.push_back(deck.drawCard());

//             if(player.sumHand() > HAND_SUM_MAX) {
//                 cout << "\nPlayer " + to_string(counter) + " : ";
//                 player.printHand();
//                 cout << "BUST!\n";
//                 state = TurnState::turnEnd;
//             }
//             else {
//                 state = TurnState::prompt;
//             }

//             break;
//         }
//         case TurnState::invalid: {
//             break;
//         }

//         default:
//             cout << "Default reached, how??";
//     }
    // End of switch
// }