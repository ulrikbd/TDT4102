#include "Blackjack.h"

Blackjack::Blackjack(CardDeck cardDeck, Player playerOne, Player dealer):
cardDeck{cardDeck},playerOne{playerOne},dealer{dealer}
{   
    cout << "La oss spille blackjack!\n";
    cardDeck.shuffle();
}

Player::Player() {
}

void Player::getNewCard(Card card) {
    hand.push_back(card);
}

int Player::getHandValue() {
    int handValue = 0;
    int aces = 0;
    int cardValue;
    for (int i = 0; i < hand.size(); ++i) {
        cardValue = hand[i].getValue();
        if (cardValue == 14) {
            aces++;
            handValue += cardValue;
        } else if(cardValue < 14 && cardValue > 9) {
            handValue += 10;
        } else {
            handValue += cardValue;
        }
    }  
    for (int j = 0; j < aces; ++j) {
        if (handValue > 21) {
            handValue -= 13;
        }  
    }
    return handValue;
}

void Player::printHand() {
    for (int i = 0; i < hand.size(); ++i) {
        cout << hand[i].toStringShort() << " ";
    }
}

void Player::printHandDealer() {
    for (int i = 1; i < hand.size(); ++i) {
        cout << hand[i].toStringShort() << " ";
    }
}

bool Player::checkRealBlackjack() {
    if (hand.size() == 2 && getHandValue() == 2 && (hand[0].getValue() == 14 || hand[1].getValue() == 14)) {
        return true;
    } else return false;
}

void Blackjack::showCards() {
    cout << "Dine kort: ";
    playerOne.printHand();
    cout << "\nDealerens kort: ";
    dealer.printHandDealer();
}

void Blackjack::checkWinner() {
    int playerOneHandValue = playerOne.getHandValue();
    int dealerHandValue = dealer.getHandValue();
    int winnerToken = 1;
    if (dealerHandValue >= playerOneHandValue && dealerHandValue <=21) winnerToken = 0;
    else if (playerOneHandValue > 21) winnerToken = 0;
    if (playerOne.checkRealBlackjack() && !dealer.checkRealBlackjack()) winnerToken = 1;

    if (winnerToken == 1) {
        cout << "Gratulerer!\nDine kort: ";
        playerOne.printHand();
        cout << "\nDealerens kort: ";
        dealer.printHand();
    } else {
        cout << "Beklager! Dine kort: ";
        playerOne.printHand();
        cout << "\nDealerens kort: ";
        dealer.printHand();
    }
    cout << '\n';
}

void Blackjack::newRound() {
    cardDeck.renewDeck();
    cardDeck.shuffle();
    giveNewHands();
    int answer;
    do {
        showCards();
        cout << '\n';
        cout << "0) Bli\n";
        cout << "1) Nytt kort\n";
        cout << "Ditt valg: ";

        cin >> answer;
        cout << '\n';

        switch (answer) {
            case 0:
                while (dealer.getHandValue() < 17 && !dealer.checkRealBlackjack()) {
                    dealer.getNewCard(cardDeck.drawCard());
                }
                break;
            case 1: 
                playerOne.getNewCard(cardDeck.drawCard());
                if (dealer.getHandValue() < 17 && !dealer.checkRealBlackjack()) {
                    dealer.getNewCard(cardDeck.drawCard());
                }
                break;
            default: {
                cout << "Prøv igjen!\n";
            }    
        }
    } while (playerOne.getHandValue() < 21 && answer != 0);
    checkWinner();
    cout << '\n';
}

void Player::getNewHand(CardDeck &cards) {
    hand.clear();
    getNewCard(cards.drawCard());
    getNewCard(cards.drawCard());
}

void Blackjack::giveNewHands() {
    playerOne.getNewHand(cardDeck);
    dealer.getNewHand(cardDeck);
}