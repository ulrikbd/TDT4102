#include "std_lib_facilities.h"
#include <iostream>

int maxOfTwo(int a, int b) {
	if (a > b) {
		cout << "A is greater than B\n";
		return a;
	} else {
		cout << "B is greater or equal to A\n";
		return b;
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for (int i = 1; i < n + 1; ++i) {
		cout << i << " " << b << '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "---";
	return b;
}

int squareSumNum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i * i;
		cout << i * i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Trianglenumbers below " << n << ":\n";
	while (acc < n) {
		cout << acc << endl;
		acc += num;
		num++;
	}
}

bool isPrime(int n) {
	for (int j = 2; j < n; j++) {
		if (n % j == 0) {
			return false;
		} else {
			return true;
		}
	}
}

void naivePrimeNumberSearch(int n) {
	for (int x = 2; x < n; x++) {
		if (isPrime(x)) {
			cout << x << " is a prime" << '\n';
		}
	}
}

int findGreatestDivisor(int n) {
	for (int divisor = n -1; divisor > 0; divisor--) {
		if (n % divisor == 0) {
			return divisor;
		}
	}
}

int main() {
	//Oppgave a)
	cout << "Oppgave a)\n"; 
	cout << maxOfTwo(1, 2) << '\n';

	// Oppgave c)
	cout << "Oppgave c)\n";
	cout << fibonacci(13) << '\n';

	//Oppgave d)
	cout << "Oppgave d)\n";
	cout << squareSumNum(5) << '\n';

	//Oppgave e)
	cout << "Oppgave e)" << '\n';
	triangleNumbersBelow(20); 
	cout << '\n';

	//Oppgave f)
	cout << "Oppgave f)" << '\n';
	cout << isPrime(13) << '\n';

	//Oppgave g)
	cout << "Oppgave g)" << '\n';
	naivePrimeNumberSearch(30);
	cout << '\n';
	
	//Oppgave h)
	cout << "Oppgave h)" << '\n';
	cout << findGreatestDivisor(35) << '\n';
}
