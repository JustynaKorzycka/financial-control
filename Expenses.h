#include <iostream>
#include <vector>
#include <sstream>
#include "Amount.h"
#include "Date.h"
#include "Conversion.h"
#ifndef EXPENSES_H
#define EXPENSES_H

using namespace std;

class Expenses
{
    Date date;
    int day, month, year;
    int numberForDates;
    int idOfSignUser;
    double amountOfExpense;
    string description;
    Amount amount;
    Conversion conversion;

public:

    Expenses();
    ~Expenses();

    void setAmountOfExpense(double amountOfExpense);
    void setDescription(string description);
    void setIdOfSignUser(int idOfSignUser);
    void setDate (Date date);
    double getAmountOfExpense();
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
