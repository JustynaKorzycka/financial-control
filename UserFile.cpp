#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "UserFile.h"
#include "Markup.h"
#include "User.h"
#include "Conversion.h"

using namespace std;


void UserFile:: loadUsersFromFile(vector <User> &Users)
{
    CMarkup xmlFile;
    string nameOfFile = "users.xml";
    string bufor = "";
    xmlFile.Load(nameOfFile);

    if(!xmlFile.FindElem("USERS"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
        xmlFile.Save(nameOfFile);
    }
    else
    {
        xmlFile.ResetPos();
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();

            while (xmlFile.FindElem("USER"))
            {
                User helpingUser;
                xmlFile.IntoElem();
                xmlFile.FindElem("USERID");
                bufor = xmlFile.GetData();
                helpingUser.setId(atoi(bufor.c_str()));
                xmlFile.FindElem("LOGIN");
                helpingUser.setLogin( xmlFile.GetData());
                xmlFile.FindElem("PASSWORD");
                helpingUser.setPassword( xmlFile.GetData());
                xmlFile.FindElem("NAME");
                helpingUser.setName( xmlFile.GetData());
                xmlFile.FindElem("SURNAME");
                helpingUser.setSurname( xmlFile.GetData());
                Users.push_back(helpingUser);
                bufor = "";
                xmlFile.OutOfElem();
                xmlFile.SavePos();
            }
    }
}

void UserFile:: addUserToFile(User user)
{
    CMarkup xmlFile;
    string nameOfFile = "users.xml";
    xmlFile.Load(nameOfFile);

        if(!xmlFile.FindElem("USERS"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
    }

    xmlFile.IntoElem();
    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("USERID", user.getId());
    xmlFile.AddElem("LOGIN", user.getLogin());
    xmlFile.AddElem("PASSWORD", user.getPassword());
    xmlFile.AddElem("NAME", user.getName());
    xmlFile.AddElem("SURNAME", user.getSurname());
    xmlFile.OutOfElem();
    xmlFile.Save(nameOfFile);
}

void UserFile::loadUsersWithChangesToFile (vector <User> users)
{
    int longOfVector = users.size();
    CMarkup xmlFile;
    string nameOfFile = "users.xml";
    xmlFile.Load(nameOfFile);
    xmlFile.ResetMainPos();

    while ( xmlFile.FindElem())
    {
    xmlFile.RemoveElem();
    }

    xmlFile.AddElem("USERS");
    xmlFile.IntoElem();

    for (vector <User>:: iterator itr = users.begin(); itr != users.end(); itr++)
    {
        xmlFile.AddElem("USER");
        xmlFile.IntoElem();
        xmlFile.AddElem("USERID", itr->getId());
        xmlFile.AddElem("LOGIN", itr->getLogin());
        xmlFile.AddElem("PASSWORD", itr->getPassword());
        xmlFile.AddElem("NAME", itr->getName());
        xmlFile.AddElem("SURNAME", itr->getSurname());
        xmlFile.OutOfElem();
        xmlFile.Save(nameOfFile);
    }
}
