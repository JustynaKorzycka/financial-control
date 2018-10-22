#include <sstream>
#include <windows.h>
#include "Amount.h"
#include "Date.h"
#include <vector>
#include "UserFile.h"
#include "User.h"
#include "Users.h"
#include <algorithm>
#include "Incomes.h"
#include "Markup.h"
#include "IncomesFile.h"
#include "Expenses.h"
#include "ExpensesFile.h"
#ifndef USERSBILANS_H
#define USERSBILANS_H

using namespace std;

class UsersBilans
{
    vector <Incomes> usersIncomes;
    vector <Expenses> usersExpenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;

public:

    UsersBilans();
    ~UsersBilans();
    void loadIncomesToVector (Users user);
    void loadExpensesToVector (Users user);
    void addIncome(Users user);
    void addExpense (Users user);
    void ExtractDataForThisMonth ();
    void ExtractDataForPreviousMonth();
    void ExtractChosenDate();
    double ShowIncomes (vector <Incomes> incomes);
    double ShowExpenses (vector  <Expenses> expenses);
    void ShowBilans (vector <Incomes> incomes, vector <Expenses> expenses);
    void SortIncomeByDates (vector <Incomes> incomes);
    void sortIncomesByDateInAscendingOrder(vector<Incomes> &selectedIncomes);
    void sortExpensesByDateInAscendingOrder(vector<Expenses> &selectedExpneses);

};



#endif
