#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Amount.h"
#include "Date.h"
#include "Conversion.h"
#ifndef INCOMES_H
#define INCOMES_H

using namespace std;

class Incomes
{
    Date date;
    int day, month, year;
    int numberForDates;
    int idOfSignUser;
    double amountOfIncome;
    string description;
    Amount amount;
    Conversion conversion;
    string allDate;

public:

    Incomes();
    ~Incomes();
    void setAmountOfIncome(double amountOfIncome);
    void setDescription(string description);
    void setIdOfSignUser(int idOfSignUser);
    void setDate (Date date);
    double getAmountOfIncome();
    string getDescription();
    string getDateInString();
    Date getDate();
    int getIdOfSignUser();
    int getDay();
    int getMonth();
    int getYear();
    void setDay (Date date);
    void setMonth(Date date);
    void setYear (Date date);
    void setNumberForDates (Date date);
    int getNumberForDates ();

};



#endif
