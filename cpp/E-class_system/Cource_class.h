#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Course {
private:
    char CourseID[10];
    char CourseName[50];
    char InstructorName[30];

public:
    // Default Constructor
    Course() {
        strcpy_s(CourseID, "");
        strcpy_s(CourseName, "");
        strcpy_s(InstructorName, "");
    }

    // Parametrized Constructor
    Course(const char* id, const char* name, const char* instructor) {
        strcpy_s(CourseID, id);
        strcpy_s(CourseName, name);
        strcpy_s(InstructorName, instructor);
    }

    // Setters
    void setCourseID(const char* id) { strcpy_s(CourseID, id); }
    void setCourseName(const char* name) { strcpy_s(CourseName, name); }
    void setInstructorName(const char* name) { strcpy_s(InstructorName, name); }

    // Getters
    const char* getCourseID() const { return CourseID; }
    const char* getCourseName() const { return CourseName; }
    const char* getInstructorName() const { return InstructorName; }

    // Display
    void displayCourse() const {
        cout << "Course ID: " << CourseID << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Instructor: " << InstructorName << endl;
    }
};
