#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class User {
protected:
    char ID[10]; //for searching
    char Username[20]; //for logging in 
    char Password[20];
    char Name[30]; //for representation

public:
    // Base class Default constructor
    User() {
        strcpy_s(ID, "");
        strcpy_s(Username, "");
        strcpy_s(Password, "");
        strcpy_s(Name, "");
    }

    // Base class Parametrized constructor
    User(const char* id, const char* username, const char* password, const char* name) {
        strcpy_s(ID, id);
        strcpy_s(Username, username);
        strcpy_s(Password, password);
        strcpy_s(Name, name);
    }

    // Base class virtual Destructor
    virtual ~User() {}

    // Setters
    void setID(const char* id) { strcpy_s(ID, id); }
    void setUsername(const char* username) { strcpy_s(Username, username); }
    void setPassword(const char* password) { strcpy_s(Password, password); }
    void setName(const char* name) { strcpy_s(Name, name); }

    // Getters
    const char* getID() const { return ID; }
    const char* getUsername() const { return Username; }
    const char* getPassword() const { return Password; }
    const char* getName() const { return Name; }

    //Pure virtual DisplayMenu
    virtual void DisplayMenu() = 0;
};