#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"
#include "masterVisual.h"


void playMastermind() {
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    constexpr int size = 4;
    constexpr int letters = 6;
    string code;
    string guess;
    int correctCharactersAndPosition;
    int correctCharacters;
    int tries = 0;
    code = randomizeString(size, 'A', 'A' + letters - 1);
    addGuess(mwin, code, size, 'A', tries);
    tries++;
    do { 
        
        hideCode(mwin, size);    
        guess = mwin.getInput(size, 'A', 'A' + letters - 1);
        correctCharacters = checkCharacters(code, guess);
        correctCharactersAndPosition = checkCharactersAndPosition(code, guess);
        addGuess(mwin, guess, size, 'A', tries);
        cout << "Din gjetning: " << guess << "\nPå riktig plass: " <<
        correctCharactersAndPosition << "\nRiktig bokstav, men feil plass: " <<
        correctCharacters - correctCharactersAndPosition << '\n';
        addFeedback(mwin, correctCharactersAndPosition, correctCharacters, size, tries);
        tries ++;

    } while (correctCharactersAndPosition < size && tries < 7);
    if (code == guess) {
        cout << "Gratulerer du klarte det!\n";
    } else {
        cout << "Bedre lykke neste gang! Koden var \n" << code << '\n';
    }
    mwin.redraw(); 
}


int checkCharactersAndPosition(string code, string guess) {
    int sum = 0;
    for (int i = 0; i < code.size(); ++i) {
        if (code[i] == guess[i]) sum++;
    }
    return sum;
}


int checkCharacters(string code, string guess) {
    int sum = 0;
    vector<char> usedChars;
    for (int i = 0; i < code.size(); ++i) {
        int sameCharsCode = countChar(code, guess[i]);
        int sameCharsGuess = countChar(guess, guess[i]);
        if (sameCharsCode == sameCharsGuess && 
            count(usedChars.begin(), usedChars.end(), guess[i]) == 0) {
                sum += sameCharsCode;
                usedChars.push_back(guess[i]);
        } else if (count(usedChars.begin(), usedChars.end(), guess[i]) == 0) {
            sum += min(sameCharsGuess, sameCharsCode);
            usedChars.push_back(guess[i]);
        }
    }
    return sum;
}







