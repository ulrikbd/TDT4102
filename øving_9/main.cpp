#include "fibonacci.h"
#include "Matrix.h"
#include "tests.h"
#include "dummyTest.h"


int main()
{
	int answer;
	do {
		cout << "Meny:\n";
		cout << "0) Avslutt\n";
		cout << "1) createFibonacci()\n";
		cout << "2) Matrix\n";
		cout << "3) dummyTest()\n";
		cout << "4) testMatrixArithemtic()\n";

		cin >> answer;
		switch (answer) {
			case 0: {
				cout << "Takk for nå!\n";
				break;
			}
			case 1: {
				createFibonacci();
				cout << '\n';
				break;
			}
			case 2: {
				testMatrix();
				cout << '\n';
				break;
			}
			case 3: {
				dummyTest();	 
				cout << '\n';
				break;
			}
			case 4: {
				testMatrixArithmetic();
				cout << '\n';
				break;
			}
			default: {
				cout << "Prøv igjen!\n";
			}
		}
	} while (answer != 0);

	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return 0;
}
