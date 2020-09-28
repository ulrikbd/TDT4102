#include "CardDeck.h"

CardDeck::CardDeck() {
    Suit currentSuit = Suit::clubs;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::diamonds;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::hearts;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::spades;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
}

void CardDeck::swap(int i, int j) {
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

void CardDeck::print() {
    for (int i = 0; i < cards.size(); ++i) {
        cards[i].toString();
        cout << '\n';
    }
}

void CardDeck::shuffle() {
    for (int k = 0; k < 52; ++k) {
        int i = rand() % 52;
        int j = rand() % 52;
        swap(i, j);
    }
}

Card CardDeck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

void CardDeck::renewDeck() {
    cards.clear();
    Suit currentSuit = Suit::clubs;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::diamonds;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::hearts;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    currentSuit = Suit::spades;
    for (int i = 2; i < 15; ++i) {
        Card card(currentSuit, (Rank)i);
        cards.push_back(card);
    }
    shuffle();
}