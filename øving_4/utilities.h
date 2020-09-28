#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);


void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);


void swapNumbers(int& a, int& b);


void randomizeVector(vector<int>& v, int n);


void sortVector(vector<int>&);


double medianOfVector(const vector<int>& v);


struct Student {
    public:
        string name;
        string studyProgram;
        int age;
};


void printStudent(Student student);


string randomizeString(int length, char lowerLimit, char upperLimit);


string readInputToString(int length, char lowerLimit, char upperLimit);


int countChar(string inputString, char letter);

