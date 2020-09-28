#include "std_lib_facilities.h"
#include "Car.h"
#include "tests.h"
#include "MeetingWindow.h"
#include "GUI.h"


int main()
{	
	int answer;
	do {
		cout << "Meny: \n";
		cout << "0) Avslutt\n";
		cout << "1) testPerson()\n";
		cout << "2) testMeeting()\n";
		cout << "3) GUI\n";

		cin >> answer;
		switch (answer)
		{
		case 0: {
			cout << "Takk for nå!\n";
			break;
		}
		case 1: {
			testPerson();
			cout << '\n';
			break;
		}
		case 2: {
			testMeeting();
			cout << '\n';
			break;
		}
		case 3: {
			MeetingWindow win{topLeft, w, h, "MeetingWindow"};
			gui_main();
			win.printPeople();
			break;
		}
		default: {
			cout << "Prøv igjen!\n";
			break;
		}}
	} while (answer != 0);

	keep_window_open();
}
