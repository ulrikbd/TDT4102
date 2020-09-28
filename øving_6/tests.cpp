#include "tests.h"

void testWriteToFile() {
    writeToFile();
}

void testReadFromFile() {
    readFromFile();
}

void testCourseCatalog() {
    CourseCatalog courses;
    cout << courses << '\n';
    courses.addCourse("TDT4100", "ITGK");
    courses.addCourse("TMA4150", "Algebra");
    cout << courses << '\n';
    cout << courses.getCourse("TDT4102") << '\n';
    cout << courses.getCourse("TDT4100") << '\n';
    courses.removeCourse("TDT4100");
    courses.addCourse("TDT4102", "C++");
    cout << courses << '\n';
    courses.writeToFile();
}

void testTemps() {
    vector<Temps> temps = tempsToVector("temperatures.txt");
    cout << "Itererer gjennom vectoren: \n";
    Temps t;
    for (int i = 0; i < temps.size(); ++i) {
        t = temps[i];
        cout << t.min << "\t" << t.max << '\n';
    }
}