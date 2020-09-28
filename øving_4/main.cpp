#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

//1 a) Kodeforståelse: v0 endres ikke, dvs den fortsatt vil være 5



int main()
{
	int answer;
	do {
		cout << "Menysystem:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) testCallByValue()" << endl;
		cout << "2) testCallByValue()" << endl;
		cout << "3) testVectorSorting()" << endl;
		cout << "4) testPrintStudent()" << endl;
		cout << "5) testString()" << endl;
		cout << "6) testReadOutputToString()" << endl;
		cout << "7) testCountChar()" << endl;
		cout << "8) playMastermind()" << endl;
		cout << "9) testCheckCharacters()" << endl;
		cout << "Velg et tall: ";

		cin >> answer;
		
		switch (answer) {
			case 0: {
				cout << "Takk for nå!\n";
				break;
			}
			case 1: {
				testCallByValue();
				cout << '\n';
				break;
			}
			case 2: {
				testCallByReference();
				cout << '\n';
				break;
			}
			case 3: {
				testVectorSorting();
				cout << "\n\n";
				break;
			}
			case 4: {
				testPrintStudent();
				cout << "\n";
				break;
			}
			case 5: {
				testString();
				cout << "\n\n";
				break;
			}
			case 6: {
				testReadInputToString();
				
				cout << '\n';
				break;
			}
			case 7: {
				testCountChar();
				cout << '\n';
				break;
			}
			case 8: {
				playMastermind();
				cout << '\n';
				break;
			}
			case 9: {
				testCheckCharacters();
				cout << '\n';
				break;
			}
			default: {
				cout << "Ikke en gyldig verdi, prøv igjen!\n\n";
			}
		}
	} while (answer != 0);
	return gui_main();
	keep_window_open();
}
