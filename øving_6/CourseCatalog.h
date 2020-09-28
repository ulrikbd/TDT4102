#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
    private: 
        map<string, string> courses;
    public:
        CourseCatalog();
        friend ostream& operator<<(ostream& out, const CourseCatalog& courseCatalog);
        void addCourse(string courseCode, string courseName);
        void removeCourse(string courseCode);
        string getCourse(string courseCode);
        void writeToFile();
};
