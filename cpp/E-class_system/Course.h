#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Assignment {
private:
    string title;
    string courseCode;
    int grade;

public:
    Assignment(string Title, string CourseCode, int Grade = -1): title(Title), courseCode(CourseCode), grade(Grade) {}

    void setGrade(int grade) {
        this->grade = grade;
    }

    void displayAssignment() const {
        cout << title;
        if (grade != -1) {
            cout << " - Grade: " << grade << endl;
        }
        else {
            cout << " - Not Graded Yet\n";
        }
    }

    string getTitle() const { return title; }
    string getCourseCode() const { return courseCode; }
    int getGrade() const { return grade; }
};

class Course {
private:
    string name;
    string code;
    Assignment* assignments[10];
    int assignmentCount;

public:
    Course(string Name = "", string Code = "") : name(Name), code(Code), assignmentCount(0) {}

    void addAssignment(string title) {
        if (assignmentCount < 10) {
            assignments[assignmentCount++] = new Assignment(title, code);
        }
        else {
            cout << "Cannot add more assignments. Maximum limit reached.\n";
        }
    }

    void displayCourse() const {
        cout << name << " (" << code << ")\n";
    }

    void displayAssignments() const {
        cout << "Assignments for " << name << ":\n";
        for (int i = 0; i < assignmentCount; ++i) {
            assignments[i]->displayAssignment();
        }
    }

    Assignment* getAssignment(int index) {
        if (index >= 0 && index < assignmentCount) {
            return assignments[index];
        }
        return nullptr;
    }

    // Student uploads assignment
    void submitAssignment(const string& assignmentTitle, const string& studentID, const string& content) {
        string filename = "submissions_" + code + "_" + assignmentTitle + "_" + studentID + ".txt";
        ofstream outFile(filename);
        if (outFile) {
            outFile << "Student ID: " << studentID << "\n";
            outFile << "Assignment Title: " << assignmentTitle << "\n";
            outFile << "Course Code: " << code << "\n";
            outFile << "Submission Content:\n" << content << "\n";
            outFile.close();
            cout << "Assignment submitted successfully!\n";
        }
        else {
            cout << "Error saving submission.\n";
        }
    }

    // Professor views student submission
    void viewSubmission(const string& assignmentTitle, const string& studentID) {
        string filename = "submissions_" + code + "_" + assignmentTitle + "_" + studentID + ".txt";
        ifstream inFile(filename);
        if (inFile) {
            string line;
            cout << "\n--- Submission by " << studentID << " for " << assignmentTitle << " ---\n";
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            cout << "--------------------------------------------\n";
            inFile.close();
        }
        else {
            cout << "No submission found for student " << studentID << " on assignment \"" << assignmentTitle << "\".\n";
        }
    }

    // Save course + assignments to file
    void saveToFile() {
        ofstream outFile("courses.txt", ios::app);
        if (outFile) {
            outFile << name << "," << code << endl;
            for (int i = 0; i < assignmentCount; ++i) {
                outFile << assignments[i]->getTitle() << "," << assignments[i]->getCourseCode() << "," << assignments[i]->getGrade() << endl;
            }
            outFile.close();
        }
        else {
            cout << "Error opening file for writing.\n";
        }
    }

    // Load from file
    static void loadFromFile(Course courses[], int& courseCount) {
        ifstream inFile("courses.txt");
        string line;
        if (inFile) {
            while (getline(inFile, line) && courseCount < 10) {
                size_t commaPos = line.find(',');
                string courseName = line.substr(0, commaPos);
                string courseCode = line.substr(commaPos + 1);

                courses[courseCount] = Course(courseName, courseCode);
                ++courseCount;

                // Load assignments
                while (getline(inFile, line) && line != "") {
                    commaPos = line.find(',');
                    string assignmentTitle = line.substr(0, commaPos);
                    string assignmentCourseCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);
                    int assignmentGrade = stoi(line.substr(line.rfind(',') + 1));

                    courses[courseCount - 1].addAssignment(assignmentTitle);
                    courses[courseCount - 1].getAssignment(courseCount - 1)->setGrade(assignmentGrade);
                }
            }
            inFile.close();
        }
        else {
            cout << "Error opening file for reading.\n";
        }
    }
};

