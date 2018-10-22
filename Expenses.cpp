#include <iostream>
#include <vector>
#include <sstream>
#include "Amount.h"
#include "Date.h"
#include "Conversion.h"
#include "Expenses.h"

using namespace std;

Expenses::Expenses()
{
    double amountOfExpense = 0;
    string description = "";
    int idOfSignUser = 0;
    int year = 0;
    int day = 0;
    int month = 0;
}

Expenses::~Expenses(){;}

void Expenses::setAmountOfExpense(double amountOfExpense)
{
    this->amountOfExpense = amountOfExpense;
}

void Expenses::setDescription(string description)
{
    this->description = description;
}

void Expenses:: setIdOfSignUser(int idOfSignUser)
{
    this->idOfSignUser = idOfSignUser;
}

double Expenses::getAmountOfExpense()
{
    return amountOfExpense;
}

string Expenses::getDescription()
{
    return description;
}

string Expenses::getDateInString()
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
int Expenses:: getIdOfSignUser()
{
    return idOfSignUser;
}

int Expenses:: getDay()
{
    return day;
}

int Expenses:: getMonth()
{
    return date.getMonth();
}

int Expenses:: getYear()
{
    return year;
}

void Expenses:: setDay (Date date)
{
    this->day = date.getDay();
}

void Expenses:: setMonth(Date date)
{
    this->month = date.getMonth();
}

void Expenses:: setYear (Date date)
{
    this->year = date.getYear();
}

void Expenses::setDate (Date date)
{
    this->date = date;
}

Date Expenses::getDate()
{
    return date;
}

void Expenses::setNumberForDates (Date date)
{
    this->numberForDates = date.getDay()+date.getMonth()*100 + date.getYear()*10000;
}

int Expenses:: getNumberForDates ()
{
    return numberForDates;
}
