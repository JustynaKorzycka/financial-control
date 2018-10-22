#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Date.h"

using namespace std;

Date:: Date() {
    int day = 0;
    int month = 0;
    int year = 0;
    int numberOfDays = 0;
}
Date:: ~Date() {
    ;
}

int Date:: getDay() {
    return day;
}

int Date:: getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

int Date:: getNumberOfDays() {
    return numberOfDays;
}

void Date:: setYear(int year) {
    this->year = year;
}

void Date:: setDay (int day) {
    this->day = day;
}

void Date:: setMonth (int month) {
    this->month = month;
}

void Date:: setNumberOfDays(int month, int year) {
    if (month == 1 || month == 3 || month ==5 ||month == 7 || month == 8 || month ==10 || month ==12) {
        this->numberOfDays = 31;

    } else if (month == 2) {

        if (((year % 4 == 0) && (year%100 !=0))||(year % 400 == 0)) {
            this->numberOfDays = 29;
        } else this->numberOfDays = 28;

    } else this->numberOfDays = 30;
}

void Date :: setTodayDate() {

    SYSTEMTIME st;
    GetLocalTime(&st);
    setYear (st.wYear);
    setMonth (st.wMonth);
    setDay (st.wDay);
    setNumberOfDays(st.wMonth, st.wYear);
}



void Date :: setDifferentDate() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    string allData;
    int ifCorrect = 0;
    int yyear = 0, mmonth = 0, dday = 0;

    while (ifCorrect != 3)
    {
    ifCorrect = 0;
    cout << "Podaj date w formacie rrrr-mm-dd: ";
    cin >> allData;
    int lenght = allData.length();
    if (lenght != 10) {
    cout << "Zly format daty. ";
    break;}
    for (int i = 0; i < 3; i++) {
        size_t position = allData.find('-');
        {
            string bufor = allData.substr(0, position);
            allData.erase(0, position + 1);
            if (i == 0) {
                yyear = atoi(bufor.c_str());
                if (yyear < 2000 || yyear > st.wYear ) {
                    cout << "Nie poprawny rok. " << endl;
                    break;
                } else {
                    setYear(yyear);
                    ifCorrect ++;
                }
            } else if(i == 1) {
                mmonth = atoi(bufor.c_str());
                if (mmonth < 1 || mmonth > 12 || (st.wYear == yyear && mmonth > st.wMonth )) {
                    cout << "Nie poprawny miesiac. " << endl;
                    break;
                } else {
                    setMonth(mmonth);
                    ifCorrect ++;
                }
            } else if (i == 2)
            {
                dday = atoi(bufor.c_str());
                setNumberOfDays(getMonth(), getYear());
                if (dday < 1 || dday > getNumberOfDays() ||(st.wYear == yyear && st.wMonth == mmonth && dday > st.wDay )) {
                    cout << "Nie poprawny dzien. " << endl;
                    break;
                } else {
                    setDay(dday);
                    ifCorrect ++;
                }
            }
        }
    }
}
}



