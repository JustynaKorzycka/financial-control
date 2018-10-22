#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "Amount.h"
#include "Users.h"
#include "Date.h"
#include "Incomes.h"
#include "Markup.h"
#include "Conversion.h"
#ifndef INCOMESFILE_H
#define INCOMESFILE_H

using namespace std;

class IncomesFile
{
    Conversion conversion;

public:

    void loadIncomesFromFile(vector <Incomes> &incomes, Users user);
    void loadDataFromFile(string wholeDate, Date& date);
    void addIncomeToFile(Incomes income);
};


#endif
