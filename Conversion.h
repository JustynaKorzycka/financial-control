#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#ifndef CONVERSION_H
#define CONVERSION_H

using namespace std;

class Conversion
{
public:

     string convertIntToString (int data);
     string doubleToString(double number);
     double stringToDouble (string word);
};

#endif
