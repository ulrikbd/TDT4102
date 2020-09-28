#include "std_lib_facilities.h"

void multiplicationTable() {
    int row;
    int column;
    int max_row;
    int max_column;
    const int width = 6;

    cout << "Gangetabbellen:" << endl;
    cout << "Antall rader: ";
    cin >> max_row;
    cout << endl;

    cout << "Antall kollonner: ";
    cin >> max_column;
    cout << endl;

    for (row = 1; row <= max_row; row++) {
        for (column = 1; column <= max_column; column++) {
            cout << setw(width) << row * column;
        }
        cout << '\n';
    }
}