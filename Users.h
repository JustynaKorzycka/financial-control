#include <iostream>
#include <vector>
#include <sstream>
#include "UserFile.h"
#include "Markup.h"
#include "User.h"
#ifndef USERS_H
#define USERS_H

using namespace std;

class Users
{
    vector <User> users;
    int idOfSignUser;
    UserFile userFile;

public:

    Users();
    virtual ~ Users();
    int getIdOfSignUser ();
    void setIdOfSignUser(int idOfSignUser);
    string changeFirstLetterToCapital(string &wordForChange);
    void logIn();
    void registerIn();
    void changePassword();

};


#endif
