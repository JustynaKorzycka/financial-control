#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <string>
#include "Amount.h"
#include "Conversion.h"
#include "Incomes.h"
#include "Date.h"
#include "IncomesFile.h"
#include "Markup.h"

using namespace std;

void IncomesFile::loadDataFromFile(string wholeDate, Date &date)
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

void IncomesFile:: loadIncomesFromFile(vector <Incomes> &incomes, Users user)
{
    CMarkup xmlFile;
    string nameOfFile = "incomes.xml";
    string bufor = "";
    xmlFile.Load(nameOfFile);

    if(!xmlFile.FindElem("INCOMES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");
        xmlFile.Save(nameOfFile);
    }
    else
    {
        xmlFile.ResetPos();
        xmlFile.FindElem("INCOMES");
        xmlFile.IntoElem();
            while (xmlFile.FindElem("INCOME"))
            {
                Incomes helpingIncome;
                Date helpingDate;
                xmlFile.IntoElem();
                xmlFile.FindElem("IDUSER");
                bufor = xmlFile.GetData();
                if (atoi(bufor.c_str()) == user.getIdOfSignUser())
                {
                helpingIncome.setIdOfSignUser(atoi(bufor.c_str()));
                xmlFile.FindElem("DATA");
                bufor = xmlFile.GetData();
                loadDataFromFile(bufor, helpingDate);
                helpingIncome.setDate(helpingDate);
                helpingIncome.setDay(helpingDate);
                helpingIncome.setMonth(helpingDate);
                helpingIncome.setYear(helpingDate);
                xmlFile.FindElem("DESCRIPTION");
                helpingIncome.setDescription( xmlFile.GetData());
                xmlFile.FindElem("AMOUNT");
                bufor = xmlFile.GetData();
                helpingIncome.setAmountOfIncome(conversion.stringToDouble(bufor));
                incomes.push_back(helpingIncome);
                }
                bufor = "";
                xmlFile.OutOfElem();
                xmlFile.SavePos();
            }
    }
}

 void IncomesFile:: addIncomeToFile(Incomes income)
 {
    CMarkup xmlFile;
    string nameOfFile = "incomes.xml";
    xmlFile.Load(nameOfFile);

        if(!xmlFile.FindElem("INCOMES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");
    }

    string amount = "";
    amount = conversion.doubleToString(income.getAmountOfIncome());
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOME");
    xmlFile.IntoElem();
    xmlFile.AddElem("IDUSER", income.getIdOfSignUser());
    xmlFile.AddElem("DATA", income.getDateInString());
    xmlFile.AddElem("DESCRIPTION", income.getDescription());
    xmlFile.AddElem("AMOUNT", amount);
    xmlFile.OutOfElem();
    xmlFile.Save(nameOfFile);
 }


