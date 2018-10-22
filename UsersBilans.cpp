#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "Amount.h"
#include "Incomes.h"
#include "Date.h"
#include "IncomesFile.h"
#include "Markup.h"
#include "UsersBilans.h"
#include "User.h"
#include "Users.h"
#include "UserFile.h"
#include "Expenses.h"
#include "ExpensesFile.h"

using namespace std;

UsersBilans::UsersBilans()
{
 ;
}

UsersBilans::~UsersBilans(){;}

void UsersBilans::loadIncomesToVector (Users user)
{
    incomesFile.loadIncomesFromFile(usersIncomes,user);
}

void UsersBilans::loadExpensesToVector (Users user)
{
    expensesFile.loadExpenseFromFile(usersExpenses, user);
}

void UsersBilans::addIncome(Users user)
{
    Incomes income;
    Date date;
    Amount amount;
    string characteristic = "";
    string amountOfIncome = "";
    bool ifCorrect = false;
    string choice = "";
    cout << "Z jakiego dnia pochodzi przychod? Wybierz 1 jesli jest z dzisiaj, wybierz inny przycisk jesli z innego dnia: ";
    cin >> choice;

    if (choice == "1")
    {
        date.setTodayDate ();
    }

    else date.setDifferentDate();
    income.setDate(date);
    income.setDay(date);
    income.setMonth(date);
    income.setYear(date);
    cin.sync();
    cout << "Czego dotyczy przychod? ";
    getline(cin, characteristic);

    while (characteristic == "")
    {
        cin.sync();
        cout << "Musisz wprowadzic kategorie przychodu. ";
        getline(cin, characteristic);
    }

    income.setDescription(characteristic);

    while (ifCorrect == false)
    {
    cout << "Podaj kwote przychodu: ";
    cin >> amountOfIncome;
    amount.changeCommaToDot(amountOfIncome);
    double aamount = amount.changeStringToDouble (amountOfIncome);
    ifCorrect = amount.checkIfAmountIsBiggerThanZero(aamount);
    if (ifCorrect == false) cout << "Kwota nie moze byc ujemna. ";
    else if (ifCorrect == true ) income.setAmountOfIncome(aamount);
    }

    int id = user.getIdOfSignUser();
    income.setIdOfSignUser(id);
    incomesFile.addIncomeToFile(income);
    usersIncomes.push_back(income);
    cout << "Przychod zostal dodany.";
    Sleep(1500);
}

void UsersBilans::addExpense (Users user)
{
    Expenses expense;
    Date date;
    Amount amount;
    string characteristic = "";
    string amountOfExpense = "";
    bool ifCorrect = false;
    string choice = "";
    cout << "Z jakiego dnia pochodzi wydatek? Wybierz 1 jesli jest z dzisiaj, wybierz inny przycisk jesli z innego dnia: ";
    cin >> choice;

    if (choice == "1")
    {
        date.setTodayDate ();
    }

    else date.setDifferentDate();

    expense.setDate(date);
    expense.setDay(date);
    expense.setMonth(date);
    expense.setYear(date);
    cin.sync();
    cout << "Czego dotyczy wydatek? ";
    getline(cin, characteristic);

    while (characteristic == "")
    {
        cin.sync();
        cout << "Musisz wprowadzic kategorie przychodu. ";
        getline(cin, characteristic);
    }

    expense.setDescription(characteristic);

    while (ifCorrect == false)
    {
    cout << "Podaj kwote wydatku: ";
    cin >> amountOfExpense;
    amount.changeCommaToDot(amountOfExpense);
    double aamount = amount.changeStringToDouble (amountOfExpense);
    getchar;
    ifCorrect = amount.checkIfAmountIsBiggerThanZero(aamount);

    if (ifCorrect == false) cout << "Kwota nie moze byc ujemna. ";
    else if (ifCorrect == true ) expense.setAmountOfExpense(aamount);
    }

    int id = user.getIdOfSignUser();
    expense.setIdOfSignUser(id);
    usersExpenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
    cout << "Wydatek zostal dodany.";
    Sleep(1500);
}

void UsersBilans::sortIncomesByDateInAscendingOrder(vector<Incomes> &selectedIncomes)
{
    sort(selectedIncomes.begin(), selectedIncomes.end(), [](Incomes& firstIncome, Incomes& secondIncome)
    {
       return firstIncome.getNumberForDates() < secondIncome.getNumberForDates();
    });
}

void UsersBilans::sortExpensesByDateInAscendingOrder(vector<Expenses> &selectedExpneses)
{
    sort(selectedExpneses.begin(), selectedExpneses.end(), [](Expenses& firstExpnese, Expenses& secondExpense)
    {
       return firstExpnese.getNumberForDates() < secondExpense.getNumberForDates();
    });
}

double UsersBilans::ShowIncomes (vector <Incomes> incomes)
{
    double amountOfIncomes = 0;
    cout << "Przychody: " << endl;
    cout << "---------------------------" << endl;

     if (!incomes.empty())
    {
        sortIncomesByDateInAscendingOrder(incomes);

    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr)
    {

        cout << itr->getDateInString() << "\t";
        cout << itr->getAmountOfIncome() << "\t"<< "\t";
        amountOfIncomes += itr->getAmountOfIncome();
        cout << itr->getDescription() << endl << endl;
    }
    }
    else cout << "Nie masz przychodow z tego okresu" << endl;

    return amountOfIncomes;
}
double UsersBilans::ShowExpenses (vector  <Expenses> expenses)
{
    double amountOfExpenses = 0;
    cout << "Wydatki: " << endl;
    cout << "---------------------------" << endl;
    if (!expenses.empty())
    {
        sortExpensesByDateInAscendingOrder(expenses);

    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); ++itr)
    {

        cout << itr->getDateInString() << "\t";
        cout << itr->getAmountOfExpense() << "\t"<< "\t";
        amountOfExpenses += itr->getAmountOfExpense();
        cout << itr->getDescription() << endl << endl;
    }
    return amountOfExpenses;
    }
    else cout << "Nie masz przychodow z tego okresu" << endl;
}

void UsersBilans::ShowBilans (vector <Incomes> incomes, vector <Expenses> expenses )
{
    double amountOfIncomes = ShowIncomes(incomes);
    double amountOfExpenses = ShowExpenses(expenses);
    double amountOfSavings = amountOfIncomes - amountOfExpenses;

    cout << "Suma przychodzow: " << amountOfIncomes << endl;
    cout << "Suma wydatkow: " << amountOfExpenses << endl;

    if (amountOfSavings > 0 ) cout << "Udalo ci sie zaoszczedzic " << amountOfSavings << endl;
    else if (amountOfSavings == 0) cout << "W tym okresie wyszedles na zero." << endl;
    else cout << "W tym okresie bilans jest na minusie i wynosi: " << amountOfSavings*(-1) <<endl;

    getch();
}

void UsersBilans::ExtractDataForThisMonth()
{
    vector <Incomes> incomesForThisMonth;
    vector <Expenses> expensesForThisMonth;
    Incomes helpingIncomes;
    Expenses helpingExpense;

    SYSTEMTIME st;
    GetLocalTime(&st);
    int thisMonth = st.wMonth;
    int thisYear = st.wYear;

    for (vector <Incomes>:: iterator itr = usersIncomes.begin(); itr != usersIncomes.end(); itr++)
    {
        if( itr->Incomes::getYear() == thisYear && itr->Incomes::getMonth() == thisMonth)
        {
            helpingIncomes.setDescription(itr->getDescription());
            helpingIncomes.setAmountOfIncome(itr->getAmountOfIncome());
            helpingIncomes.setDate(itr->getDate());
            helpingIncomes.setNumberForDates(itr->getDate());
            incomesForThisMonth.push_back(helpingIncomes);
        }
    }

    for (vector <Expenses>:: iterator itr = usersExpenses.begin(); itr != usersExpenses.end(); itr++)
    {
        if( itr->Expenses::getYear() == thisYear && itr->Expenses::getMonth() == thisMonth)
        {
            helpingExpense.setDescription(itr->getDescription());
            helpingExpense.setAmountOfExpense(itr->getAmountOfExpense());
            helpingExpense.setDate(itr->getDate());
            helpingExpense.setNumberForDates(itr->getDate());
            expensesForThisMonth.push_back(helpingExpense);
        }
    }

    ShowBilans (incomesForThisMonth, expensesForThisMonth);
}

void UsersBilans::ExtractDataForPreviousMonth()
{
    vector <Incomes> incomesForPreviousMonth;
    vector <Expenses> expensesForPreviousMonth;
    Incomes helpingIncomes;
    Expenses helpingExpense;
    int MonthMinusOne = 0;

    SYSTEMTIME st;
    GetLocalTime(&st);
    int thisMonth = st.wMonth;
    int thisYear = st.wYear;

    if (thisMonth == 1)
    {
        MonthMinusOne = 12;
        thisYear -= 1;
    }

    else  MonthMinusOne = thisMonth - 1;

    for (vector <Incomes>:: iterator itr = usersIncomes.begin(); itr != usersIncomes.end(); itr++)
    {
        if( itr->Incomes::getYear() == thisYear && itr->Incomes::getMonth() == MonthMinusOne)
        {
            helpingIncomes.setDescription(itr->getDescription());
            helpingIncomes.setAmountOfIncome(itr->getAmountOfIncome());
            helpingIncomes.setDate(itr->getDate());
            helpingIncomes.setNumberForDates(itr->getDate());
            incomesForPreviousMonth.push_back(helpingIncomes);
        }
    }

    for (vector <Expenses>:: iterator itr = usersExpenses.begin(); itr != usersExpenses.end(); itr++)
    {
        if( itr->Expenses::getYear() == thisYear && itr->Expenses::getMonth() == MonthMinusOne)
        {
            helpingExpense.setDescription(itr->getDescription());
            helpingExpense.setAmountOfExpense(itr->getAmountOfExpense());
            helpingExpense.setDate(itr->getDate());
            helpingExpense.setNumberForDates(itr->getDate());
            expensesForPreviousMonth.push_back(helpingExpense);
        }
    }

    ShowBilans (incomesForPreviousMonth, expensesForPreviousMonth);
}
void UsersBilans:: ExtractChosenDate()
{
    Date dateOfBeginigOfBilans;
    Date dateOfEndOfBilans;
    vector <Incomes> incomesForChosenDate;
    vector <Expenses> expensesForChosenDate;
    Incomes helpingIncomes;
    Expenses helpingExpense;

    cout << "Data poczatku bilansu: " <<endl;
    dateOfBeginigOfBilans.setDifferentDate();
    cout << endl;

    cout << "Data konca bilansu: " <<endl;
    dateOfEndOfBilans.setDifferentDate();

    int NumberOfFirstDate = dateOfBeginigOfBilans.getDay() + dateOfBeginigOfBilans.getMonth() *100 + dateOfBeginigOfBilans.getYear() * 10000;
    int NumberOfLastDate = dateOfEndOfBilans.getDay() + dateOfEndOfBilans.getMonth() *100 + dateOfEndOfBilans.getYear() * 10000;
    cout << endl;

    for (vector <Incomes>:: iterator itr = usersIncomes.begin(); itr != usersIncomes.end(); itr++)
    {
        int sum = itr->Incomes::getYear()*10000 + itr->Incomes::getMonth()*100 + itr->Incomes::getDay();
        if (sum >= NumberOfFirstDate && sum <= NumberOfLastDate)
      {
            helpingIncomes.setDescription(itr->getDescription());
            helpingIncomes.setAmountOfIncome(itr->getAmountOfIncome());
            helpingIncomes.setDate(itr->getDate());
            helpingIncomes.setNumberForDates(itr->getDate());
            incomesForChosenDate.push_back(helpingIncomes);
      }
    }

    for (vector <Expenses>:: iterator itr = usersExpenses.begin(); itr != usersExpenses.end(); itr++)
    {
        int sum = itr->Expenses::getYear()*10000 + itr->Expenses::getMonth()*100 + itr->Expenses::getDay();
        if (sum >= NumberOfFirstDate && sum <= NumberOfLastDate)
        {
            helpingExpense.setDescription(itr->getDescription());
            helpingExpense.setAmountOfExpense(itr->getAmountOfExpense());
            helpingExpense.setDate(itr->getDate());
            helpingExpense.setNumberForDates(itr->getDate());
            expensesForChosenDate.push_back(helpingExpense);
        }
    }

    ShowBilans (incomesForChosenDate, expensesForChosenDate);
}











