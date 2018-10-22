#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#ifndef AMOUNT_H
#define AMOUNT_H

using namespace std;


class Amount
{
public:

    void changeCommaToDot (string& amountToChange);
    double changeStringToDouble (string amountToChange);
    bool checkIfAmountIsBiggerThanZero(double money);

};






#endif
