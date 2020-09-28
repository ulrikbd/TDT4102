#include "std_lib_facilities.h"

vector<int> calculateSeries(int beløp, int rente, int år) {
    vector<int> innbetaling(år);
    const int fast_avdrag = beløp/år;

    // cout.width(5);
    // cout << left << "År" << setw(16) << right << "Innbetaling" << endl;
    for (int i = 0; i < år; i++) {
        double temp_avdrag = static_cast<double>(rente)/100*beløp;
        int temp_innbetaling = fast_avdrag + temp_avdrag;

        beløp -= fast_avdrag;

        innbetaling[i] = temp_innbetaling;
        // cout.width(5);
        // cout << left << i + 1 << setw(10) << right << innbetaling[i] << endl;
    }
return innbetaling;
}

vector<int> calculateAnnuity(int beløp, int rente, int år) {
    int årligInnbetaling = beløp*rente/100*(1/(1 - 1/pow(1 + static_cast<double>(rente)/100, år)));
    vector<int> innbetaling(år);
    
    // cout.width(5);
    // cout << left << "År" << setw(16) << right << "Innbetaling" << endl;
    for (int i = 0; i < år; i++) {
        innbetaling[i] = årligInnbetaling;
        // cout.width(5);
        // cout << left << i + 1 << setw(10) << right << innbetaling[i] << endl;
    }
    return innbetaling;
}

void loanDifference() {
    int beløp, rente, år;
    int total_series = 0;
    int total_annuity = 0;

    cout << "Beløp: ";
    cin >> beløp;
    cout << '\n' << "Rente: ";
    cin >> rente;
    cout << '\n' << "År: ";
    cin >> år;
    cout << endl;
 
    vector<int> series = calculateSeries(beløp, rente, år);
    vector<int> annuity = calculateAnnuity(beløp, rente, år);

    for (int i = 0; i < år; i++) {
        total_annuity += annuity[i];
        total_series += series[i];
    }

    cout.width(7);
    cout << left << "År";
    cout.width(15);
    cout << right << "Annuitet";
    cout.width(15);
    cout << "Serie";
    cout.width(15);
    cout << "Differanse" << endl;
    for (int i = 0; i < år; i++) {
        cout.width(7);
        cout << left << i + 1;
        cout.width(14);
        cout << right << annuity[i];
        cout.width(15);
        cout << series[i];
        cout.width(15);
        cout << annuity[i]-series[i] << endl;
    }    
    cout.width(7);
    cout << left << "Total";
    cout.width(14);
    cout << right << total_annuity;
    cout.width(15);
    cout << total_series;
    cout.width(15);
    cout << total_annuity - total_series << endl;
}