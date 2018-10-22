#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Amount.h"
#include "Incomes.h"
#include "Date.h"
#include "Conversion.h"

using namespace std;

Incomes::Incomes()
{
    double amountOfIncome = 0;
    string description = "";
    int idOfSignUser = 0;
    int year = 0;
    int day = 0;
    int month = 0;
    int numberForDates = 0;
}

Incomes::~Incomes(){;}


void Incomes::setAmountOfIncome(double amountOfIncome)
{
    this->amountOfIncome = amountOfIncome;
}

void Incomes::setDescription(string description)
{
    this->description = description;
}

void Incomes:: setIdOfSignUser(int idOfSignUser)
{
    this->idOfSignUser = idOfSignUser;
}

double Incomes::getAmountOfIncome()
{
    return amountOfIncome;
}

string Incomes::getDescription()
{
    return description;
}

string Incomes::getDateInString()
{
    string allDate = "";
    int yyear = date.getYear();
    string yearInString = conversion.convertIntToString(yyear);
    int mmonth = date.getMonth();
    string monthInString = conversion.convertIntToString(mmonth);
    int dday = date.getDay();
    string dayInString = conversion.convertIntToString(dday);

    allDate = yearInString + "-";
    if (mmonth < 10) allDate = allDate + "0" + monthInString + "-";
    else allDate = allDate + monthInString + "-";
    if (dday <10) allDate = allDate + "0" + dayInString;
    else allDate = allDate + dayInString;
    return allDate;
}

int Incomes:: getIdOfSignUser()
{
    return idOfSignUser;
}

int Incomes:: getDay()
{
    return day;
}

int Incomes:: getMonth()
{
    return date.getMonth();
}

int Incomes :: getYear()
{
    return year;
}

void Incomes :: setDay (Date date)
{
    this->day = date.getDay();
}

void Incomes ::setMonth(Date date)
{
    this->month = date.getMonth();
}

void Incomes ::setYear (Date date)
{
    this->year = date.getYear();
}

void Incomes::setDate (Date date)
{
    this->date = date;
}

Date Incomes::getDate()
{
    return date;
}

void Incomes::setNumberForDates (Date date)
{
    this->numberForDates = date.getDay()+date.getMonth()*100 + date.getYear()*10000;
}

int Incomes:: getNumberForDates ()
{
    return numberForDates;
}


