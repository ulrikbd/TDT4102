#include "std_lib_facilities.h"
#include "Animal.h"
#include "tests.h"
#include "Graph.h"
#include "Emoji.h"
#include "Simple_window.h"

using namespace Graph_lib;

//1a) Public: Kan hentes utenfor klassen, private: Kan ikke det,
//protected: kan ikke hentes utenfor, men i spesialiseringer

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = xmax/10;


int main()
{
	int a;
	do {
		cout << "Meny:\n";
		cout << "1) testAnimal()\n";
		cout << "2) Emoji\n";
		cout << "0) Avslutt\n";
		cout << "Ditt valg: ";

		cin >> a;
		switch (a) {
			case 0:
				cout << "Takk for nå!\n";
				break;
			case 1: {
				testAnimal();
				cout << '\n';
				break;
			}
			case 2: {
				const Point tl{100, 100};
				const string win_label{"Emoji factory"};
				Simple_window win{tl, xmax, ymax, win_label};
				Vector_ref<Emoji> emojis;

				smileyFace smiley(Point{emojiRadius, ymax/2}, emojiRadius);
				WinkingFace winkingsmiley(Point{3*emojiRadius, ymax/2}, emojiRadius);
				SurprisedFace surprisedsmiley(Point{5*emojiRadius, ymax/2}, emojiRadius);
				sadFace sadsmiley(Point{7*emojiRadius, ymax/2}, emojiRadius);
				AngryFace angrysmiley(Point{9*emojiRadius, ymax/2}, emojiRadius);

				emojis.push_back(smiley);
				emojis.push_back(winkingsmiley);
				emojis.push_back(surprisedsmiley);
				emojis.push_back(sadsmiley);
				emojis.push_back(angrysmiley);

				for (int i = 0; i < emojis.size(); ++i) {
					emojis[i].attach_to(win);
				}

				win.wait_for_button();
				break;
			}
			default: {
				cout << "Prøv igjen!\n";
				break;
			}
		}
	} while (a != 0);

	keep_window_open();
}
