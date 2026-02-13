#pragma once
#include<iostream>
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

    DateAndTime(int d, int m, int y, int h, int min) : Day(d), Month(m), Year(y), Hour(h), Minute(min) {}

    void displayDateTime() const {
        cout << Day << "/" << Month << "/" << Year << " " << Hour << ":" << (Minute < 10 ? "0" : "") << Minute << endl;
    }
};
