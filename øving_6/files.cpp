#include "files.h"


void writeToFile() {
    string filename;
    cout << "Navn på filen du vil skrive til: ";
    cin >> filename;
    cout << '\n';
    string word;
    ofstream outfile{filename};
    cout << "Neste ord('quit' for å avslutte): ";
    while (cin >> word && word != "quit") {
        cout << "Neste ord('quit' for å avslutte): ";
        outfile << word << '\n';
    }
    outfile.close();
}

void readFromFile() {
    string inFilename;
    string outFilename;
    cout << "Navn på filen du vil lese fra: ";
    cin >> inFilename;
    ifstream infile{inFilename};

    if (infile) {
        cout << "\nNavn på filen du vil skrive til: ";
        cin >> outFilename;
        string line;
        
        ofstream outfile{outFilename};
        int linenumber = 1;
        while (getline(infile, line)) {
            outfile << linenumber << ". " << line << '\n';
            linenumber ++;
        }
    } else cout << "Filen eksisterer ikke!";
}