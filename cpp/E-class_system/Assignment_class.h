#pragma once
#include<iostream>
#include<cstring>
#include"DateAndTime_class.h"
using namespace std;

class Assignment {
private:
    char AssignmentID[10];
    char CourseID[10];  // Link to Course
    char Title[50];
    char Description[200];
    DateAndTime DueDate;

public:
    // Default Constructor
    Assignment() {
        strcpy_s(AssignmentID, "");
        strcpy_s(CourseID, "");
        strcpy_s(Title, "");
        strcpy_s(Description, "");
    }

    // Parametrized Constructor
    Assignment(const char* aid, const char* cid, const char* title, const char* desc, DateAndTime due)
        : DueDate(due) {
        strcpy_s(AssignmentID, aid);
        strcpy_s(CourseID, cid);
        strcpy_s(Title, title);
        strcpy_s(Description, desc);
    }

    // Setters
    void setAssignmentID(const char* aid) { strcpy_s(AssignmentID, aid); }
    void setCourseID(const char* cid) { strcpy_s(CourseID, cid); }
    void setTitle(const char* title) { strcpy_s(Title, title); }
    void setDescription(const char* desc) { strcpy_s(Description, desc); }
    void setDueDate(const DateAndTime& due) { DueDate = due; }

    // Getters
    const char* getAssignmentID() const { return AssignmentID; }
    const char* getCourseID() const { return CourseID; }
    const char* getTitle() const { return Title; }
    const char* getDescription() const { return Description; }
    DateAndTime getDueDate() const { return DueDate; }

    // Display
    void displayAssignment() const {
        cout << "Assignment ID: " << AssignmentID << endl;
        cout << "Course ID: " << CourseID << endl;
        cout << "Title: " << Title << endl;
        cout << "Description: " << Description << endl;
        // (You should also display DueDate here properly)
    }
};
