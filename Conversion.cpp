#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Conversion.h"

using namespace std;

string Conversion:: convertIntToString (int data)
{
    ostringstream ss;
    ss << data;
    string str = ss.str();
    return str;
}

string Conversion::doubleToString(double number)
{
    stringstream sstream;
    sstream << fixed << setprecision(2) << number;
    return sstream.str();
}

double Conversion::stringToDouble (string word)
{
    double number = 0.0;
    stringstream ss;

    ss << word;
    ss >> number;

return number;
}


