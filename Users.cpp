#include <iostream>
#include <vector>
#include <sstream>
#include "UserFile.h"
#include "Markup.h"
#include "User.h"
#include "Users.h"
#include <windows.h>
#include <algorithm>

using namespace std;

Users:: Users()
{
    this->idOfSignUser = 0;
    userFile.loadUsersFromFile(users);
}

Users:: ~Users(){;};

int Users:: getIdOfSignUser()
{
    return idOfSignUser;
}

void Users::setIdOfSignUser(int idOfSignUser)
{
    this->idOfSignUser = idOfSignUser;
}

string Users:: changeFirstLetterToCapital(string &wordForChange)
{
    if (!wordForChange.empty()) {
        transform(wordForChange.begin(), wordForChange.end(), wordForChange.begin(), ::tolower);
        wordForChange[0] = toupper(wordForChange[0]);
    }
    return wordForChange;
}
void Users::logIn()
{
    string givenLogin = "";
    string givenPassword = "";
    bool ifExist = false;
    int numberOfTests = 3;
    cout << "Podaj login: ";
    cin >> givenLogin;

    for (vector <User> :: iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> User::getLogin() == givenLogin) {
            ifExist = true;

            while (numberOfTests > 0)  {
                cout << "Podaj haslo. Pozostalo prob " << numberOfTests << " : ";
                cin >> givenPassword;
                if (itr -> User::getPassword() == givenPassword) {
                    this->idOfSignUser = itr ->User::getId();
                    cout << "No to zaczynamy ogarniac finanse!";
                    Sleep (1000);
                    break;
                }
                numberOfTests --;
            }
            if (numberOfTests == 0) {
                cout << "Niepoprawne logowanie";
                Sleep(1000);
                break;
            }
        }
    }
    if (ifExist == false) cout << "Nie ma takiego uzytkownika. ";

    Sleep(1000);
}

void Users::registerIn()
{
    string givenLogin, givenPassword, givenName, givenSurname;
    int numberOfUsers = users.size();
    User helpingUser;
    bool ifNotExist;

    cout << "Wprowadz nazwe uzytkownika: ";
    cin >> givenLogin;
    do{
    for (vector <User> :: iterator itr = users.begin(); itr != users.end(); ++itr) {
                ifNotExist = true;
        if (itr -> getLogin() == givenLogin) {
            cout << "Wprowadzona nazwa jest juz zajeta. Podaj inna nazwe uzytkownika: ";
            cin >> givenLogin;
            ifNotExist = false;
        }
    }

    }while (ifNotExist == false);
    helpingUser.setLogin(givenLogin);

    cout << "Podaj haslo: ";
    cin >> givenPassword;
    helpingUser.setPassword(givenPassword);

    cout << "Podaj imie: ";
    cin >> givenName;
    changeFirstLetterToCapital(givenName);
    helpingUser.setName(givenName);

    cout << "Podaj nazwisko: ";
    cin >> givenSurname;
    changeFirstLetterToCapital(givenSurname);
    helpingUser.setSurname(givenSurname);

    if (numberOfUsers == 0) helpingUser.setId(1);
    else if (numberOfUsers != 0) helpingUser.setId(users.back().getId() + 1);

    userFile.addUserToFile(helpingUser);
    users.push_back(helpingUser);
    cout << "Konto zostalo pomysle zalozone." << endl;
    Sleep (1000);
    users.back().getId();
}

void Users::changePassword ()
{
    string newPassword = "";
    while (newPassword == "")
    {
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;
    }
    for (vector <User>:: iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->User::getId() == getIdOfSignUser())
        {
            itr->User::setPassword(newPassword);
        }
    }
    userFile.loadUsersWithChangesToFile(users);
    cout << "Haslo zostalo zmienione. " << endl;
    Sleep(1000);
}


