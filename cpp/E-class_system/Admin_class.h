#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include"User_class.h"
#include"Student_class.h"
#include"Professor_class.h"
using namespace std;

class Admin : public User {
private:
    void logAction(const char* action, const char* details) const {
        std::ofstream logfile("SystemLogs.txt", std::ios::app);
        if (!logfile) {
            std::cout << "Error: Cannot open SystemLogs.txt for logging.\n";
            return;
        }

        logfile << "[" << getID() << "] "
            << "[" << action << "] "
            << details << "\n";

        logfile.close();
    }

public:
    // Admin class Default constructor
    Admin() : User() {}

    // Admin class Parametrized constructor
    Admin(const char* id, const char* username, const char* password, const char* name) : User(id, username, password, name) {}

    // Admin class Destructor
    ~Admin() override {}

    void display() const {
        cout << getID() << "\t"
            << getUsername() << "\t"
            << getPassword() << "\t"
            << getName() << "\t"
            << "-" << "\t"
            << "-" << endl;
    }

    //void ManageUsers();
    //void AddUser();
    //void AddBase();
    //void AddStudent();
    //void AddProfessor();
    //void AddAdmin();
    //void RemoveUser();
    //void RemoveStudent();
    //void RemoveProfessor();
    //void RemoveAdmin();
    //void ViewUsers();
    //void ViewStudents();
    //void ViewProfessors();
    //void ViewAdmins();
    //void ViewAll();
    //void SearchByID();
    //void ViewSystemLogs();
    //void ConfigureSettings();

    void ManageUsers() {
        int choice;
        do {
            cout << "\n=== User Managing ===\n";
            cout << "1. Add User\n";
            cout << "2. Remove User\n";
            cout << "3. View Users\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                AddUser();
                break;
            case 2:
                RemoveUser();
                break;
            case 3:
                ViewUsers();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }

    void AddUser() { //==========================================================================================================
        int choice;
        do {
            cout << "\n=== Adding User ===\n";
            cout << "1. Add Student\n";
            cout << "2. Add Professor\n";
            cout << "3. Add Admin\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                AddProfessor();
                break;
            case 3:
                AddAdmin();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }

    void AddBase(User& obj, char usertype) {
        char temp[10], temp2[20], temp3[20], temp4[30];

        cout << "ID: ";
        cin.getline(temp, 10);
        obj.setID(temp);

        cout << "Username: ";
        cin.getline(temp2, 20);
        if (temp2[0] != usertype) {
            cout << "Username should start with '" << usertype << "'\n";
            return;
        }
        obj.setUsername(temp2);

        cout << "Password: ";
        cin.getline(temp3, 20);
        obj.setPassword(temp3);

        cout << "Name: ";
        cin.getline(temp4, 30);
        obj.setName(temp4);
    }

    void AddStudent() {
        Student obj;
        char temp[10], temp1[15], temp2[20], temp3[20], temp4[30], temp5[40];
        ofstream outfile("Students.dat", ios::binary | ios::app);

        if (!outfile) {
            cout << "Error opening Students.dat for writing." << endl;
            return;
        }

        cout << "Enter the student's data:" << endl;

        AddBase(obj, 'S');

        cout << "Enter the email adress: ";
        cin.getline(temp5, 40);
        obj.setStudentEmail(temp5);

        cout << "Enter the phone number: ";
        cin.getline(temp1, 15);
        obj.setStudentPhoneNumber(temp1);

        outfile.write((char*)(&obj), sizeof(obj));
        outfile.close();
        logAction("AddStudent", (string("Added student ") + obj.getID() + ": " + obj.getName()).c_str());
    }

    void AddProfessor() {
        Professor obj;
        char temp1[10], temp2[20], temp3[20], temp4[30], temp5[40];
        ofstream outfile("Professors.dat", ios::binary | ios::app);

        if (!outfile) {
            cout << "Error opening Professors.dat for writing." << endl;
            return;
        }

        cout << "Enter the professor's data:" << endl;

        AddBase(obj, 'P');

        cout << "Enter the email adress: ";
        cin.getline(temp5, 40);
        obj.setProfessorEmail(temp5);

        outfile.write((char*)(&obj), sizeof(obj));
        outfile.close();
        logAction("AddProfessor", (string("Added professor ") + obj.getID() + ": " + obj.getName()).c_str());
    }

    void AddAdmin() {
        Admin obj;
        char temp[10], temp2[20], temp3[20], temp4[30];
        ofstream outfile("Admins.dat", ios::binary | ios::app);

        if (!outfile) {
            cout << "Error opening Admins.dat for writing." << endl;
            return;
        }

        cout << "Enter the admin's data:" << endl;

        AddBase(obj, 'A');

        outfile.write((char*)(&obj), sizeof(obj));
        outfile.close();
        logAction("AddAdmin", (string("Added admin ") + obj.getID() + ": " + obj.getName()).c_str());
    }

    void RemoveUser() {//================================================================================================================
        int choice;
        do {
            cout << "\n=== Removing User (by ID) ===\n";
            cout << "1. Remove Student\n";
            cout << "2. Remove Professor\n";
            cout << "3. Remove Admin\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                RemoveStudent();
                break;
            case 2:
                RemoveProfessor();
                break;
            case 3:
                RemoveAdmin();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }

    template <typename T>
    void RemoveBase(const char* dataFile, const char* tempFile, const char* roleName) {
        char targetID[10];
        cout << "Enter the " << roleName << " ID to remove: ";
        cin.getline(targetID, 10);

        ifstream infile(dataFile, ios::binary);
        ofstream outfile(tempFile, ios::binary);

        if (!infile || !outfile) {
            cout << "Error opening files for " << roleName << " removal." << endl;
            return;
        }

        T obj;
        bool found = false;

        while (infile.read((char*)(&obj), sizeof(obj))) {
            if (strcmp(obj.getID(), targetID) != 0) {
                outfile.write((char*)(&obj), sizeof(obj));
            }
            else {
                found = true;
                cout << roleName << " with ID " << targetID << " removed successfully.\n";
                logAction("RemoveStudent", (string("Removed ") + roleName + " ID: " + targetID).c_str());
            }
        }

        infile.close();
        outfile.close();

        remove(dataFile);
        rename(tempFile, dataFile);

        if (!found) {
            cout << "No " << roleName << " with ID " << targetID << " found.\n";
        }
    }

    void RemoveStudent() {
        RemoveBase<Student>("Students.dat", "TempStudents.dat", "Student");
    }

    void RemoveProfessor() {
        RemoveBase<Professor>("Professors.dat", "TempProfessors.dat", "Professor");
    }

    void RemoveAdmin() {
        RemoveBase<Admin>("Admins.dat", "TempAdmins.dat", "Admin");
    }

    void ViewUsers() {//================================================================================================================
        int choice;
        do {
            cout << "\n=== Viewing Users ===\n";
            cout << "1. View Students\n";
            cout << "2. View Professors\n";
            cout << "3. View Admins\n";
            cout << "4. View All\n";
            cout << "5. Search by ID\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                ViewStudents();
                break;
            case 2:
                ViewProfessors();
                break;
            case 3:
                ViewAdmins();
                break;
            case 4:
                ViewAll();
                break;
            case 5:
                SearchByID();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }

    template <typename T>
    void ViewBase(const char* dataFile, const char* roleName) {
        ifstream infile(dataFile, ios::binary);

        if (!infile) {
            cout << "Error opening " << dataFile << " for viewing " << roleName << "s.\n";
            return;
        }

        T obj;
        bool found = false;

        cout << "\n=== List of " << roleName << "s ===\n";
        cout << "ID\tUsername\tPassword\tName\tEmail\tPhone\n";
        cout << "------------------------------------------------------------\n";

        while (infile.read((char*)(&obj), sizeof(obj))) {
            obj.display();
            found = true;
        }

        infile.close();

        if (!found) {
            cout << "No " << roleName << "s found.\n";
        }
    }

    void ViewStudents() {
        ViewBase<Student>("Students.dat", "Student");
    }

    void ViewProfessors() {
        ViewBase<Professor>("Professors.dat", "Professor");
    }

    void ViewAdmins() {
        ViewBase<Admin>("Admins.dat", "Admin");
    }

    void ViewAll() {
        ViewBase<Student>("Students.dat", "Student");
        ViewBase<Professor>("Professors.dat", "Professor");
        ViewBase<Admin>("Admins.dat", "Admin");
    }

    template<typename T>
    void SearchBase(const char* filename, const char* targetID, const char* roleName) {
        T obj; bool found = false;
        ifstream infile(filename, ios::binary);
        if (!infile.is_open()) {
            throw string("Cannot open file: ") + filename;
        }

        while (infile.read((char*)(&obj), sizeof(T))) {
            if (strcmp(obj.getID(), targetID) == 0) {
                cout << "\n=== " << roleName << " Found ===\n";
                cout << "ID\tUsername\tPassword\tName\tEmail\tPhone\n";
                cout << "------------------------------------------------------------\n";
                obj.display();
                found = true;
                infile.close();
                return;
            }
        }
        if (!found) {
            cout << "The user is not found\n";
        }
        infile.close();
    }

    void SearchByID() {
        char targetID[10];
        cout << "\nEnter the ID you are looking for:";
        cin.getline(targetID, 10);
        char usertype = targetID[0];

        switch (usertype) {
        case 'S':
            SearchBase<Student>("Students.dat", targetID, "Student");
            break;
        case 'P':
            SearchBase<Professor>("Professors.dat", targetID, "Professor");
            break;
        case 'A':
            SearchBase<Admin>("Admins.dat", targetID, "Admin");
            break;
        default:
            cout << "Wrong ID formatting. Id should start from 'S', 'P' or 'A'!";
            break;
        }
    }

    void ManageFiles() {
        int choice;
        do {
            cout << "\n=== File Managing ===\n";
            cout << "1. Create file\n";
            cout << "2. Clear file\n";
            cout << "3. Rename file\n";
            cout << "4. Remove file\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                CreateFile();
                break;
            case 2:
                ClearFile();
                break;
            case 3:
                RenameFile();
                break;
            case 4:
                RemoveFile();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }

    void CreateFile() {
        char filename[50];
        cout << "Enter name of file to create: ";
        cin.getline(filename, 50);

        ofstream file(filename, ios::binary);
        if (file) {
            cout << "File '" << filename << "' created successfully.\n";
            logAction("CreateFile", (string("Name of created file: ") + filename).c_str());
        }
        else {
            cout << "Failed to create file.\n";
        }
    }

    void ClearFile() {
        char filename[50];
        cout << "Enter name of file to clear: ";
        cin.getline(filename, 50);

        ofstream file(filename, ios::binary | ios::trunc);
        if (file) {
            cout << "File '" << filename << "' cleared successfully.\n";
            logAction("CleareFile", (string("Name of cleared file: ") + filename).c_str());
        }
        else {
            cout << "Failed to clear file.\n";
        }
    }

    void RenameFile() {
        char oldName[50], newName[50];
        cout << "Enter current filename: ";
        cin.getline(oldName, 50);
        cout << "Enter new filename: ";
        cin.getline(newName, 50);

        if (rename(oldName, newName) == 0) {
            cout << "File renamed to '" << newName << "' successfully.\n";
            logAction("RenameFile", (string("Old name: ") + oldName + string(", new name: ") + newName).c_str());
        }
        else {
            perror("Error renaming file");
        }
    }

    void RemoveFile() {
        char filename[50];
        cout << "Enter name of file to remove: ";
        cin.getline(filename, 50);

        if (remove(filename) == 0) {
            cout << "File '" << filename << "' removed successfully.\n";
            logAction("RemoveFile", (string("Name of removed file: ") + filename).c_str());
        }
        else {
            perror("Error removing file");
        }
    }

    void ViewSystemLogs() {
        ifstream logfile("SystemLogs.txt");

        if (!logfile) {
            cout << "Error: Could not open SystemLogs.txt\n";
            return;
        }

        string line;
        cout << "\n=== System Logs ===\n";
        while (getline(logfile, line)) {
            cout << line << "\n";
        }

        logfile.close();
    }

    void DisplayMenu() override {
        int choice;
        do {
            cout << "\n=== Admin Menu ===\n";
            cout << "1. Manage Users\n";
            cout << "2. Manage Files\n";
            cout << "3. View System logs\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                ManageUsers();
                break;
            case 2:
                ManageFiles();
                break;
            case 3:
                ViewSystemLogs();
                break;
            case 0:
                cout << "logging out\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 0);
    }
};