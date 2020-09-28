#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment;
    }
}

//1e)
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//Bruker pass-by-reference her for ryddigere kode uten return-value


//2)
void randomizeVector(vector<int>& v, int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        int randomPercentage = rand();
        randomPercentage = randomPercentage % 101;
        v.push_back(randomPercentage);
    }
}

//3)
void sortVector(vector<int>& v) {
    int i = 1;
    int j;
    while (i < v.size()) {
        j = i;
        while (j > 0 && v[j-1] > v[j]) {
            swapNumbers(v[j-1], v[j]);
            --j;
        }
        ++i;
    }
}

//Spørsmål: static_cast double ser ikke ut til å virke på medianen, returnerer som int?
double medianOfVector(const vector<int>& v) {
    int size = v.size();
    double median;

    if (size % 2 == 0) {
        int roofedMiddle = size/2;
        median = static_cast<double>((v[roofedMiddle] + v[roofedMiddle - 1]) / 2.0);  //Calculates median
    } else {
        median = v[size/2];
    }

    return median;
}

//4)
void printStudent(Student student) {
    cout << "Studenten heter " << student.name << " er " << student.age
    << " år gammel og studerer " << student.studyProgram << ".\n";
}

//5)
string randomizeString(int length, char lowerLimit, char upperLimit) {
    string randomString;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < length; ++i) {
        int randNum = rand();
        randNum = randNum % (upperLimit - lowerLimit + 1);
        randomString += lowerLimit + randNum;
    }
    return randomString;
}

string readInputToString(int length, char lowerLimit, char upperLimit) {
    string outputString;
    if (length == 0) {
        return "";
    }

    lowerLimit = tolower(lowerLimit);
    upperLimit = tolower(upperLimit);
    int check;
    string tempString;

    do {
        check = 0;
        cout << "Skriv inn " << length << " tegn mellom " << lowerLimit << " og " << upperLimit << endl;
        cin >> outputString;
        cout << '\n';
        for (int i = 0; i < outputString.size(); ++i) {
            if (tolower(outputString[i]) <  lowerLimit || tolower(outputString[i] > upperLimit)) {
                check++;
            }
        }
        if (check != 0 || outputString.size() != length) cout << "Prøv igjen!\n";
    } while (check != 0 ||  outputString.size() != length);
    return outputString;
}


int countChar(string inputString, char letter) {
    int sum = 0;

    for (int i = 0; i < inputString.size(); ++i) {
        if (inputString[i] == letter) sum++;
    }
    return sum;
}