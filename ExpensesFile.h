#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "Amount.h"
#include "Users.h"
#include "Date.h"
#include "Expenses.h"
#include "Markup.h"
#include "Conversion.h"
#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

using namespace std;

class ExpensesFile
{
    Conversion conversion;

public:

    void loadExpenseFromFile(vector <Expenses> &expenses, Users user);
    void loadDataFromFile(string wholeDate, Date &date);
    void addExpenseToFile(Expenses expense);
};


#endif
