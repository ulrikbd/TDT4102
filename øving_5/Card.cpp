#include "Card.h"


string suitToString(Suit suit) {
    map<Suit, string> mapSuit;
    mapSuit.insert(pair<Suit, string>(Suit::clubs, "Clubs"));
    mapSuit.insert(pair<Suit, string>(Suit::diamonds, "Diamonds"));
    mapSuit.insert(pair<Suit, string>(Suit::hearts, "Hearts"));
    mapSuit.insert(pair<Suit, string>(Suit::spades, "Spades"));

    return mapSuit[suit];
}

string rankToString(Rank rank) {
    map<Rank, string> mapRank;
    mapRank.insert(pair<Rank, string>(Rank::two, "Two"));
    mapRank.insert(pair<Rank, string>(Rank::three, "Three"));
    mapRank.insert(pair<Rank, string>(Rank::four, "Four"));
    mapRank.insert(pair<Rank, string>(Rank::five, "Five"));
    mapRank.insert(pair<Rank, string>(Rank::six, "Six"));
    mapRank.insert(pair<Rank, string>(Rank::seven, "Seven"));
    mapRank.insert(pair<Rank, string>(Rank::eight, "Eight"));
    mapRank.insert(pair<Rank, string>(Rank::nine, "Nine"));
    mapRank.insert(pair<Rank, string>(Rank::ten, "Ten"));
    mapRank.insert(pair<Rank, string>(Rank::jack, "Jack"));
    mapRank.insert(pair<Rank, string>(Rank::queen, "Queen"));
    mapRank.insert(pair<Rank, string>(Rank::king, "King"));
    mapRank.insert(pair<Rank, string>(Rank::ace, "Ace"));

    return mapRank[rank];
}

//1 e) Teori: Fordelene med å bruke symboler er typechecking,
//man kan ikke skrive deimønds ved uhell. Vi kan også lettere 
//gi verdiene egenskaper


Card::Card(Suit suit, Rank rank)
:s{suit},r{rank}
{
}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

void Card::toString() {
    cout << rankToString(r) << " of " << suitToString(s);
}

string Card::toStringShort() {
    string outputString ;
    int intRank = r;
    outputString = suitToString(s)[0] + to_string(intRank);
    return outputString;
}

int Card::getValue() {
    int value = (int)r;
    return value;
}
