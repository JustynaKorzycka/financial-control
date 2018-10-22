#include <iostream>
#include <vector>
#include "Date.h"
#include "User.h"
#include "Users.h"
#include "Markup.h"
#include "UserFile.h"
#include "Amount.h"
#include "Incomes.h"
#include "IncomesFile.h"
#include "Expenses.h"
#include "ExpensesFile.h"
#include "UsersBilans.h"

using namespace std;


int main()
{
    char firstChoice;
    Users user;

    while (1) {
        system ("cls");
        if (user.getIdOfSignUser() == 0) {
            cout << "Menu logowania " << endl;
            cout << "---------------------" << endl;
            cout << "1. Logowanie " <<endl;
            cout << "2. Rejestracja " <<endl;
            cout << "3. Wyjscie z programu " << endl;

            cin >> firstChoice;
            switch (firstChoice) {
            case '1': {
                user.logIn();
                break;
            }
            case '2': {
                user.registerIn();
                break;
            }

            case '3':
                exit(0);
                break;
            }
        }

        else if (user.getIdOfSignUser() != 0) {
            UsersBilans usersBilans;
            usersBilans.loadIncomesToVector(user);
            usersBilans.loadExpensesToVector(user);
            char secoundChoice;

            while (user.getIdOfSignUser() != 0) {
                system("cls");
                cout << "Menu" << endl;
                cout << "--------------------" << endl;
                cout << "1. Dodaj przychod" << endl;
                cout << "2. Dodaj wydatek" << endl;
                cout << "3. Bilans z biezacego miesiaca" << endl;
                cout << "4. Bilans z poprzedniego miesiaca" << endl;
                cout << "5. Bilans z wybranego okresu"<<endl;
                cout << "6. Zmiana hasla" << endl;
                cout << "7. Wyloguj" << endl;
                cout << "8. Wyjdz z programu" << endl;
                cin >> secoundChoice;

                if (secoundChoice == '1') {
                    system("cls");
                    usersBilans.addIncome(user);
                } else if (secoundChoice == '2') {
                    system("cls");
                    usersBilans.addExpense(user);
                } else if (secoundChoice == '3') {
                    system("cls");
                    usersBilans.ExtractDataForThisMonth();
                } else if (secoundChoice == '4') {
                    system("cls");
                    usersBilans.ExtractDataForPreviousMonth();
                } else if (secoundChoice == '5') {
                    system("cls");
                    usersBilans.ExtractChosenDate();
                } else if (secoundChoice == '6') {
                    system("cls");
                    user.changePassword();
                } else if (secoundChoice == '7') {
                   user.setIdOfSignUser(0);
                    break;
                } else if (secoundChoice == '8') exit(0);

    }
        }
    }




    return 0;
}
