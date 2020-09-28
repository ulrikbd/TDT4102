#include "CourseCatalog.h"

CourseCatalog::CourseCatalog() {
    addCourse("TDT4102", "Prosedyre- og objekt-orientert programmering");
}

ostream& operator<<(ostream& out, const CourseCatalog& courseCatalog) {
    for (auto m: courseCatalog.courses) {
        out << m.first << " - " << m.second << '\n';
    }
    return out;
}

void CourseCatalog::addCourse(string courseCode, string courseName) {
    if (courses.count(courseCode) > 0) courses[courseCode] = courseName;
    else courses.insert(pair<string, string>(courseCode, courseName));
}

void CourseCatalog::removeCourse(string courseCode) {
    courses.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode) {
    string outputString = courses[courseCode];
    return outputString;
}

void CourseCatalog::writeToFile() {
    string filename = "course_catalog.txt";
    ofstream outfile{filename};
    map<string, string>::iterator it;
    for (it = courses.begin(); it != courses.end(); ++it) {
        outfile << it->first << " "  << it->second << '\n';
    }
}