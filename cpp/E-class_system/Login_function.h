#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include"User_class.h"
#include"Student_class.h"
#include"Professor_class.h"
#include"Admin_class.h"
using namespace std;

template<typename T>
T* authenticateUser(const char* filename, const char* username, const char* password) {
    T obj;
    ifstream infile(filename, ios::binary);
    if (!infile.is_open()) {
        throw string("Cannot open file: ") + filename;
    }

    while (infile.read(<char*>(&obj), sizeof(T))) {
        if (strcmp(obj.getUsername(), username) == 0 && strcmp(obj.getPassword(), password) == 0) {
            cout << "\nLogin successful!\n";
            infile.close();
            return new T(obj);
        }
    }

    infile.close();
    return nullptr;
}

User* Login() {
    for (int attempt = 0; attempt < 3; ++attempt) {
        char username[20], password[20];
        cout << "\n=== Login Attempt " << attempt + 1 << " ===\n";
        cout << "Username: ";
        cin.getline(username, 20);
        cout << "Password: ";
        cin.getline(password, 20);

        try {
            char usertype = username[0];
            User* userPtr = nullptr;

            if (usertype == 'S') {
                userPtr = authenticateUser<Student>("Students.dat", username, password);
            }
            else if (usertype == 'P') {
                userPtr = authenticateUser<Professor>("Professors.dat", username, password);
            }
            else if (usertype == 'A') {
                userPtr = authenticateUser<Admin>("Admins.dat", username, password);
            }
            else {
                throw "Invalid user type prefix in username.";
            }

            if (userPtr != nullptr) {
                return userPtr;
            }
            else
                cout << "Invalid credentials. Please try again.\n";

        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    cout << "\nToo many failed attempts. Access denied.\n";
    return nullptr;
}