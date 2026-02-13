#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class StudentCourse {
private:
    char StudentID[10];
    char CourseID[10];
public:
    StudentCourse() {
        strcpy_s(StudentID, "");
        strcpy_s(CourseID, "");
    }

    void setStudentID(const char* id) { strcpy_s(StudentID, id); }
    void setCourseID(const char* id) { strcpy_s(CourseID, id); }

    const char* getStudentID() const { return StudentID; }
    const char* getCourseID() const { return CourseID; }
};
