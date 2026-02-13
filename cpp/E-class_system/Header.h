#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class DateAndTime {
private:
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;

public:
    DateAndTime() : Day(1), Month(1), Year(2000), Hour(0), Minute(0) {}
    DateAndTime(int d, int m, int y, int h, int min) : Day(1), Month(1), Year(2000), Hour(0), Minute(0) {}
};

// ============================================== Base class ===========================================
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

// ======================================================== Derived classes ======================================================
// Student class
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

// Professor class
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

// Admin class
class Admin : public User {
public:
    // Admin class Default constructor
    Admin() : User() {}

    // Admin class Parametrized constructor
    Admin(const char* id, const char* username, const char* password, const char* name) : User(id, username, password, name) {}

    // Admin class Destructor
    ~Admin() override {}

    // Admin class DisplayMenu function
    void DisplayMenu() override {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Manage Users\n";
        cout << "2. View System Logs\n";
        cout << "3. Configure Settings\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Managing users...\n";
            cout << "1. Add User\n";
            cout << "2. Remove User\n";
            cout << "3. View Users\n";
            break;
        case 2:
            cout << "Viewing system logs...\n";
            cout << "System Log: User 'Dr.Smith' logged in at 10:00 AM.\n";
            break;
        case 3:
            cout << "Configuring settings...\n";
            cout << "1. Configure Server\n";
            cout << "2. Update System Software\n";
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

// ====================================================== Functions =============================================================

template<typename T>
T* authenticateUser(const char* filename, const char* username, const char* password) {
    T obj;
    ifstream infile(filename, ios::binary);
    if (!infile.is_open()) {
        throw runtime_error(string("Cannot open file: ") + filename);
    }

    while (infile.read(reinterpret_cast<char*>(&obj), sizeof(T))) {
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
                throw invalid_argument("Invalid user type prefix in username.");
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

void AddStudent() {
    Student obj;
    char temp[10], temp1[15], temp2[20], temp3[20], temp4[30], temp5[40];
    ofstream outfile("Students.dat", ios::binary | ios::app);

    if (!outfile) {
        cout << "Error opening Students.dat for writing." << endl;
        return;
    }

    cout << "Enter the student's data:" << endl;

    cout << "Enter the ID: "; 
    cin.getline(temp, 10);
    obj.setID(temp);

    cout << "Enter the Username: ";
    cin.getline(temp2, 20);
    if (temp2[0] != 'S') {
        cout << "Student's username should start with 'S'" << endl;
        return;
    }
    obj.setUsername(temp2);

    cout << "Enter the Password: ";
    cin.getline(temp3, 20);
    obj.setPassword(temp3);

    cout << "Enter the Name: ";
    cin.getline(temp4, 30);
    obj.setName(temp4);

    cout << "Enter the email adress: ";
    cin.getline(temp5, 40);
    obj.setStudentEmail(temp5);

    cout << "Enter the phone number: ";
    cin.getline(temp1, 15);
    obj.setStudentPhoneNumber(temp1);

    outfile.write((char*)(&obj), sizeof(obj));
    outfile.close();
}