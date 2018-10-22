#include <iostream>
#include <vector>
#ifndef USER_H
#define USER_H

using namespace std;

class User {
    int id;
    string login, password, name, surname;

public:

    User();
    virtual ~User();

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

    void setId(int id);
    void setLogin(string login);
    void setPassword (string password);
    void setName (string name);
    void setSurname (string surname);
};

#endif




