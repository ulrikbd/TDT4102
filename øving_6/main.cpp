#include "std_lib_facilities.h"
#include "files.h"
#include "tests.h"
#include "tegnstatistikk.h"
#include "CourseCatalog.h"
#include "Temps.h"
#include "Graph.h"
#include "Simple_window.h"
#include "graph.h"

using namespace Graph_lib;


int main()
{
	int answer;
	srand((unsigned) time(0));
	do {
		cout << "Meny:\n";
		cout << "0) Avslutt\n";
        cout << "1) testWriteToFile()\n";
        cout << "2) testReadFromFile()\n";
        cout << "3) countLetters()\n";
        cout << "4) testCourseCatalog()\n";
		cout << "5) testTemps()\n";
		cout << "6) Grafisk framstilling\n";
		cout << "Ditt valg: ";

		cin >> answer;
		cout << '\n';
		switch (answer) {
			case 0: {
				cout << "Takk for nå!\n";
				break;
			}
			case 1: {
				testWriteToFile();
				cout << '\n';
				break;
			}
            case 2: {
                testReadFromFile();
                cout << '\n';
                break;
            }
            case 3: {
                string infilename{"grunnlov.txt"};
                cout << infilename << '\n';
                countLetters(infilename);
                cout << '\n';
                break;
            }
            case 4: {
                testCourseCatalog();
                cout << '\n';
                break;
            }
			case 5: {
				testTemps();
				cout << '\n';
				break;
			}
			case 6: {
				vector<Temps> temps = tempsToVector("temperatures.txt");
				int  ticks = temps.size();

				double xscale = double(xlength)/ticks;

				Point tl{100, 100};

				Simple_window win{tl, xmax, ymax, 
				"Daglige maks- og minimumstemperaturer fra 3.februar 2018 til og med 3.februar 2019"};

				Axis x {Axis::x, Point{xoffset, ymax/2}, xlength, 13, 
				"Feb Mar Apr Mai Jul Jun Aug"
				" Sep Okt Nov Des Jan"};

				Axis y {Axis::y, Point{xoffset, ymax - yoffset}, ylength, 6, "Degrees [C]"};
				
				Text zero{Point{xoffset - 10, ymax/2}, "0"};
				Text minusten{Point{xoffset - 10, ymax/2 + 10/ymaxabsvalue*(ymax/2 - yoffset)}, "-10"};
				Text ten{Point{xoffset - 10, ymax/2 - 10/ymaxabsvalue*(ymax/2 - yoffset)}, "10"};
				Text minustwenty{Point{xoffset - 10, ymax/2 + 20/ymaxabsvalue*(ymax/2 - yoffset)}, "-20"};
				Text twenty{Point{xoffset - 10, ymax/2 - 20/ymaxabsvalue*(ymax/2 - yoffset)}, "20"};

				Open_polyline max;
				Open_polyline min;
				max.set_color(Color::red);
				Text max_label{Point{20, ymax/2 - 30}, "Max"};
				max_label.set_color(Color::red);
				
				min.set_color(Color::blue);
				Text min_label{Point{20, ymax/2 + 30}, "min"};
				min_label.set_color(Color::blue);

				for (int i = 0; i < temps.size(); ++i) {
					Temps t = temps[i];
					int xs = xoffset + i*xscale;
					int ytempmin = ymax/2 - t.min/ymaxabsvalue*(ymax/2 - yoffset);
					int ytempmax = ymax/2 - t.max/ymaxabsvalue*(ymax/2 - yoffset);
					min.add(Point{xs, ytempmin});
					max.add(Point{xs, ytempmax});
				}

				win.attach(max);
				win.attach(min);
				win.attach(y);
				win.attach(x);
				win.attach(max_label);
				win.attach(min_label);
				win.attach(zero);
				win.attach(minusten);
				win.attach(ten);
				win.attach(minustwenty);
				win.attach(twenty);
				
				win.wait_for_button();
				break;
			} 
			default: {
				cout << "Prøv igjen!\n";
				break;
			}
		}
	} while (answer != 0);

	keep_window_open();
	
	return 0;
}
