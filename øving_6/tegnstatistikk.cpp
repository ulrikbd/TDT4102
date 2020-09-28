#include "tegnstatistikk.h"

void countLetters(string infilename) {
    ifstream infile{infilename};
    vector<int> letterCount(26, 0);
    char c;
    while (infile >> c) {
        if (isalpha(c)) letterCount[tolower(c) - 'a']++;
    }
    for (int i = 0; i < letterCount.size(); ++i) {
        cout << static_cast<char>('a' + i) << ": " << letterCount[i] << '\t';
        if ((i + 1) % 3 == 0 ) cout << '\n';
    }
}