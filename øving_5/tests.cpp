#include "tests.h"

void testSuitAndRankToString() {
    Suit suit = Suit::clubs;
    string suitString = suitToString(suit);
    cout << "\nSuit as string: " << suitString << '\n';
    Rank rank = Rank::ace;
    string rankString = rankToString(rank);
    cout << "Rank as string: " << rankString << '\n';
}

void testGetValue() {
    Card card(Suit::clubs, Rank::ace);
    int value = card.getValue();
    cout << value;
}

void testGetHandValue() {
    Player playerOne;
    Card cardOne(Suit::clubs, Rank::six);
    playerOne.getNewCard(cardOne);
    playerOne.printHand();
    cout << "\nHandvalue: " << playerOne.getHandValue() << '\n';
    Card cardTwo(Suit::diamonds, Rank::king);
    playerOne.getNewCard(cardTwo);
    playerOne.printHand();
    cout << "\nHandvalue: " << playerOne.getHandValue() << '\n';
    Card cardThree(Suit::diamonds, Rank::ace);
    playerOne.getNewCard(cardThree);
    playerOne.printHand();
    cout << "\nHandvalue: " << playerOne.getHandValue() << '\n';
    Card cardFour(Suit::diamonds, Rank::five);
    playerOne.getNewCard(cardFour);
    playerOne.printHand();
    cout << "\nHandvalue: " << playerOne.getHandValue() << '\n';
}

void testDrawCard() {
    CardDeck cards;
    cards.print();
    Card cardOne = cards.drawCard();
    cout << "\nTrekker kort\n";
    cards.print();
    cout << "\nTrukket kort: ";
    cardOne.toString();
}