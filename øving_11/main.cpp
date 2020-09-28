#include "LinkedList.h"
#include "iterator.h"
#include <iostream>
#include "Person.h"
#include "LinkedList.h"
#include "templates.h"

using namespace std;




int main()
{
	int a;
	do {
		cout << "0) Avslutt\n";
		cout << "1) iterateVector()\n";
		cout << "2) replace()\n";
		cout << "3) iterateSet()\n";
		cout << "4) replaceSet()\n";
		cout << "5) testPerson\n";
		cout << "6) instertOrdered()\n";
		cout << "7) testLinkedList()\n";
		cout << "8) testMaximum()\n";
		cout << "9) testShuffle()\n";

		cin >> a;
		switch (a)
		{
		case 0:
			break;
		case 1: {
			iterateVector();
			cout << '\n';
			break;
		}
		case 2: {
			vector<string> v{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur"};
			replace(v, "Ipsum", "lol");
			for (const auto& p: v) cout << p << '\t';
			cout << '\n';
			break;
		} case 3: {
			iterateSet();
			cout << '\n';
			break;
		}
		case 4: {
			set<string> v{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur"};
			replaceSet(v, "Ipsum", "lol");
			for (const auto& p: v) cout << p << '\t';
			cout << '\n';
			break;
		}
		case 5: {
			Person ulrik("Ulrik", "Danielsen");
			cout << ulrik << '\n';
			Person sveinung(ulrik);
			cout << sveinung << '\n';
			sveinung = Person("Sveinung", "Aga");
			cout << sveinung << '\n';
			break;
		}
		case 6: {
			list<Person> l{Person("Ulrik", "Danielsen")};
			insertOrdered(l, Person("Sveinung", "Aga"));
			insertOrdered(l, Person("Vilde", "Eliassen"));
			insertOrdered(l, Person("Tone", "Damli"));
			for (const auto& p: l) {
				cout << p << '\n';
			}
			break;
		}
		case 7: {
			testLinkedList();
			cout << '\n';
			break;
		}
		case 8: {
			testMaximum();
			cout << '\n';
			break;
		}
		case 9: {
			testShuffle();
			cout << '\n';
			break;
		}
		default:
			cout << "Prøv igjen!\n\n";
			break;
		}

	} while (a);

	cin >> a;
}
