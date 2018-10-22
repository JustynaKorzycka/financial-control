#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#ifndef DATE_H
#define DATE_H


using namespace std;

class Date
{
    int day, month, year, numberOfDays;

public:

    Date();
    virtual~ Date();
    int getDay();
    int getMonth();
    int getYear();
    int getNumberOfDays();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setNumberOfDays(int month, int year);

    void setTodayDate ();
    void setDifferentDate();



};

#endif
