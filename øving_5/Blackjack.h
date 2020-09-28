#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class Player {
    private:
        vector<Card> hand;
    public:
        Player();
        void getNewCard(Card card);
        int getHandValue();
        void printHand();
        void printHandDealer();
        bool checkRealBlackjack();
        void getNewHand(CardDeck &cards);
};

class Blackjack {
    private:
        CardDeck cardDeck;
        Player playerOne;
        Player dealer;
    public:
        Blackjack(CardDeck cardDeck, Player playerOne, Player dealer);
        void showCards();
        void newRound();
        void checkWinner();
        void giveNewHands();
};