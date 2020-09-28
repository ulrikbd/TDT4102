#include "tests.h"
#include "utilities.h"
#include "mastermind.h"


void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}


void testCallByReference() {
    int v0 = 5;
    int temp = v0;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << temp
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << v0 << endl;
}


//2)
void testVectorSorting() {
    vector<int> percentages;
    randomizeVector(percentages, 10);
    double median = medianOfVector(percentages);
    cout << "Median før: " << median << endl;
    sortVector(percentages);
    median = medianOfVector(percentages);
    cout << "Median etter: " << median << endl; 
    cout << "{";
    for (int i = 0; i < percentages.size(); ++i) {
        cout << percentages[i];

        if (i != percentages.size() - 1) cout << ", ";

        if (i % 10 == 0 && i != 0) cout << '\n';
    }
    cout << "}";
}


//4)
void testPrintStudent() {
    Student student;
    cout << "Navn: ";
    //cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, student.name);
    cout << "\nAlder: ";
    cin >> student.age;
    cout << "\nStudieprogram: ";
    cin >> student.studyProgram;
    cout << "\nStudenten heter " << student.name << ", er " << student.age
    << " år gammel og studerer " << student.studyProgram << ".\n";
}


//5)
void testString() {
    string grades;
    double average = 0;
    grades = randomizeString(20, 'A', 'F');
    int interval = 'F' - 'A' + 1;
    cout << grades;
    cout << '\n';
    vector<int> gradeCount;
    int temp;
    char tempLetter;
    for (int i = 0; i < interval; ++i) {
        tempLetter = 'A' + i;
        temp = countChar(grades, tempLetter);
        gradeCount.push_back(temp);
    }
    for (int i = 0; i < interval; ++i) {
        average += (5 - i)*gradeCount[i];      
    }
    average = average/20.0;
    cout << "Snittet er: " << average;
}


void testReadInputToString() {
    string outputString;
    outputString = readInputToString(8, 'A', 'F');
    cout << outputString << '\n';
}


void testCountChar() {
    string inputString;
    char letter;
    int sum;

    cout << "Teller antall forekomster av en bokstav i et ord:\n";
    cout << "Ord: ";
    cin >> inputString;
    cout << "\nBokstav: ";
    cin >> letter;
    cout << '\n';
    
    sum = countChar(inputString, letter);
    cout << "Bokstaven " << letter << " forekommer " << sum << " ganger i " << inputString << ".\n";
}


void testCheckCharacters() {
    string wordOne;
    string wordTwo;
    cout << "Ord en: ";
    cin >> wordOne;
    cout << "\nOrd to: ";
    cin >> wordTwo;
    int correct = checkCharacters(wordOne, wordTwo);
    cout << "\nAntall like bokstaver: " << correct << endl;
}