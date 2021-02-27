#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <string>
#include "Amount.h"
#include "Conversion.h"
#include "Expenses.h"
#include "ExpensesFile.h"
#include "Date.h"
#include "IncomesFile.h"
#include "Markup.h"




using namespace std;

void ExpensesFile::loadDataFromFile(string wholeDate, Date &date)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    for (int i = 0; i < 3; i++) {
        size_t position = wholeDate.find('-');
        {
            string bufor = wholeDate.substr(0, position);
            wholeDate.erase(0, position + 1);
            if (i == 0) {
                int yyear = atoi(bufor.c_str());
                date.setYear(yyear);
            } else if(i == 1) {
                int mmonth = atoi(bufor.c_str());
                date.setMonth(mmonth);
            } else if (i == 2)
            {
                int dday = atoi(bufor.c_str());
                date.setDay(dday);
                }
            }
        }
    }

void ExpensesFile:: loadExpenseFromFile(vector <Expenses> &expenses, Users user)
{
    CMarkup xmlFile;
    string nameOfFile = "expenses.xml";
    string bufor = "";
    xmlFile.Load(nameOfFile);

    if(!xmlFile.FindElem("EXPENSES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");
        xmlFile.Save(nameOfFile);
    }
    else
    {
        xmlFile.ResetPos();
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();

            while (xmlFile.FindElem("EXPENSE"))
            {
                Expenses helpingExpense;
                Date helpingDate;
                xmlFile.IntoElem();
                xmlFile.FindElem("IDUSER");
                bufor = xmlFile.GetData();
                if (atoi(bufor.c_str()) == user.getIdOfSignUser())
                {
                helpingExpense.setIdOfSignUser(atoi(bufor.c_str()));
                xmlFile.FindElem("DATA");
                bufor = xmlFile.GetData();
                loadDataFromFile(bufor, helpingDate);
                helpingExpense.setDate(helpingDate);
                helpingExpense.setDay(helpingDate);
                helpingExpense.setMonth(helpingDate);
                helpingExpense.setYear(helpingDate);
                xmlFile.FindElem("DESCRIPTION");
                helpingExpense.setDescription( xmlFile.GetData());
                xmlFile.FindElem("AMOUNT");
                bufor = xmlFile.GetData();
                helpingExpense.setAmountOfExpense(conversion.stringToDouble(bufor));
                expenses.push_back(helpingExpense);
                }
                bufor = "";
                xmlFile.OutOfElem();
                xmlFile.SavePos();
            }
    }
}

 void ExpensesFile:: addExpenseToFile(Expenses expense)
 {
    CMarkup xmlFile;
    string nameOfFile = "expenses.xml";
    xmlFile.Load(nameOfFile);

        if(!xmlFile.FindElem("EXPENSES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");
    }

    string amount = "";
    amount = conversion.doubleToString(expense.getAmountOfExpense());
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSE");
    xmlFile.IntoElem();
    xmlFile.AddElem("IDUSER", expense.getIdOfSignUser());
    xmlFile.AddElem("DATA", expense.getDateInString());
    xmlFile.AddElem("DESCRIPTION", expense.getDescription());
    xmlFile.AddElem("AMOUNT", amount);
    xmlFile.OutOfElem();
    xmlFile.Save(nameOfFile);
 }


