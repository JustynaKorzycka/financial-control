#include <iostream>
#include <vector>
#include <sstream>
#include "Markup.h"
#include "User.h"
#include "Conversion.h"
#ifndef USERFILE_H
#define USERFILE_H

using namespace std;

class UserFile
{
public:

    void loadUsersFromFile(vector <User> &Users);
    void addUserToFile(User user);
    void loadUsersWithChangesToFile (vector <User> Users);

};


#endif
