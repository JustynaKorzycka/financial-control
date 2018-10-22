#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "Amount.h"

using namespace std;

void Amount::changeCommaToDot (string& amountToChange)
{
    size_t position = amountToChange.find(',');
    if (position != string::npos)
    {
        amountToChange.replace(position, 1, ".");
    }
}

double Amount::changeStringToDouble (string amountToChange)
{
    double number = atof(amountToChange.c_str());
    int numberToChange = number*100;
    double changeNumber = (double) numberToChange/100;
    return changeNumber;
}

bool Amount:: checkIfAmountIsBiggerThanZero(double money)
{
    if (money > 0) return true;
    else if (money <=0) return false;
}
