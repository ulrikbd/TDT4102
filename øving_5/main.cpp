#include "std_lib_facilities.h"
#include "Card.h"
#include "tests.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main()
{
	int answer;
	srand((unsigned) time(0));
	do {
		cout << "Meny:\n";
		cout << "0) Avslutt\n";
		cout << "1) testSuitANdRankToString()\n";
		cout << "2) Tester klassen Card\n";
		cout << "3) Tester CardDeck\n";
		cout << "4) Spill blackjack!\n";
		cout << "5) testGetValue()\n";
		cout << "6) testGetHandValue()\n";
		cout << "7) testDrawCard()\n";
		cout << "Ditt valg: ";

		cin >> answer;
		cout << '\n';
		switch (answer) {
			case 0: {
				cout << "Takk for nå!\n";
				break;
			}
			case 1: {
				testSuitAndRankToString();
				cout << '\n';
				break;
			}
			case 2: {
				Card card(Suit::diamonds, Rank::ace);
				Rank r = card.getRank();
				Suit s = card.getSuit();
				cout << "Suit: " << suitToString(s) << " Rank: " << rankToString(r) << '\n';
				card.toString();
				string shortString = card.toStringShort();
				cout << "\nshortString: " << shortString; 
				cout << '\n';
				break;
			}
			case 3: {
			    CardDeck cards;
				Player playerOne;
				Player dealer;
				Blackjack blackjackGame(cards, playerOne, dealer);

				playerOne.printHand();
				playerOne.printHandDealer();
				cout << playerOne.getHandValue();
				playerOne.getNewCard(cards.drawCard());
				playerOne.printHand();
				playerOne.printHandDealer();
				cout << playerOne.getHandValue();
			
				break;
			} 
			case 4: {
				CardDeck cards;
				Player playerOne;
				Player dealer;
				Blackjack blackjackGame(cards, playerOne, dealer);
				char roundAnswer;
				do {
					cout << "Ny runde? (j/n): ";
					cin >> roundAnswer;
					switch (roundAnswer) {
						case 'j':
							blackjackGame.newRound();
							break;
					}
				} while (roundAnswer != 'n');
				break;
			}
			case 5: {
				testGetValue();
				cout << '\n';
				break;
			}
			case 6: {
				testGetHandValue();
				break;
			}
			case 7: {
				testDrawCard();
				cout << '\n';
				break;
			}
			default: {
				cout << "Prøv igjen!\n";
				break;
			}
		}
	} while (answer != 0);

	keep_window_open();
}
