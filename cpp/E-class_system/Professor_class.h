#pragma once
#include<iostream>
#include<cstring>
#include"User_class.h"
using namespace std;

class Professor : public User {
protected:
    char Email[40];
public:
    // Professor class Default constructor
    Professor() : User() {
        strcpy_s(Email, "");
    }

    // Professor class Parametrized constructor
    Professor(const char* id, const char* username, const char* password, const char* name, const char* email) : User(id, username, password, name) {
        strcpy_s(Email, email);
    }

    // Display function
    void display() const {
        cout << getID() << "\t"
            << getUsername() << "\t"
            << getPassword() << "\t"
            << getName() << "\t"
            << Email << "\t"
            << "-" << endl;
    }


    void setProfessorEmail(const char* email) { strcpy_s(Email, email); }
    const char* getProfessorEmail() { return Email; }

    // Professor class DisplayMenu function
    void DisplayMenu() override {
        cout << "\n=== Professor Menu ===\n";
        cout << "1. View Teaching Schedule\n";
        cout << "2. Grade Assignments\n";
        cout << "3. Post Announcements\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Viewing teaching schedule...\n";
            cout << "\n--- Teaching Schedule ---\n";
            cout << "Monday: 9:00 AM - 11:00 AM: Math 101\n";
            cout << "Wednesday: 2:00 PM - 4:00 PM: Physics 101\n";
            cout << "Friday: 10:00 AM - 12:00 PM: Chemistry 101\n";
            break;
        case 2:
            cout << "Grading assignments...\n";
            cout << "Grading Assignment for Math 101...\n";
            break;
        case 3:
            cout << "Posting announcements...\n";
            cout << "Announcement posted: 'Midterm exams are scheduled for next week.'\n";
            break;
        case 0:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
};