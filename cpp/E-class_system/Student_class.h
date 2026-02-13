#pragma once
#include<iostream>
#include<cstring>
#include"User_class.h"
using namespace std;

class Student : public User {
protected:
    char Email[40];
    char PhoneNumber[15];
public:
    // Student class Default constructor
    Student() : User() {
        strcpy_s(Email, "");
        strcpy_s(PhoneNumber, "");
    }

    // Student class Parametrized constructor
    Student(const char* id, const char* username, const char* password, const char* name, const char* email, const char* phoneNumber) : User(id, username, password, name) {
        strcpy_s(Email, email);
        strcpy_s(PhoneNumber, phoneNumber);
    }

    // Student class Destructor
    ~Student() override {}

    // Display function
    void display() const {
        cout << getID() << "\t"
            << getUsername() << "\t"
            << getPassword() << "\t"
            << getName() << "\t"
            << Email << "\t"
            << PhoneNumber << endl;
    }

    // Setters
    void setStudentEmail(const char* email) { strcpy_s(Email, email); }
    void setStudentPhoneNumber(const char* phoneNumber) { strcpy_s(PhoneNumber, phoneNumber); }

    // Getters
    const char* getStudentEmail() const { return Email; }
    const char* getStudentPhoneNumber() const { return PhoneNumber; }

    // Student class DisplayMenu function
    void DisplayMenu() override {
        cout << "\n=== Student Menu ===\n";
        cout << "1. View Courses\n";
        cout << "2. Submit Assignment\n";
        cout << "3. View Grades\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Viewing courses...\n";
            cout << "Available Courses: \n";
            cout << "1. Math 101\n";
            cout << "2. English 202\n";
            cout << "3. History 303\n";
            break;
        case 2:
            cout << "Submitting assignment...\n";
            cout << "Assignment for Math 101 has been successfully submitted!\n";
            break;
        case 3:
            cout << "Viewing grades...\n";
            cout << "Your Grades: \n";
            cout << "Math 101: A\n";
            cout << "English 202: B\n";
            cout << "History 303: A-\n";
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