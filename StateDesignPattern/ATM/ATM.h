#ifndef ATM_H
#define ATM_H

#include "ATMState.h"

class ATM
{
public:
    int id;
    ATMState *atmState;

    ATM(int ids);
    void setState(ATMState *atmStat);
    void pressStartButton();
    void insertCard(int number, int cvv, std::string date);
    void enterPin(int pin);
    void enterAmount(int amount);
    void dispenseCash();
    void cancel();
};

#endif // ATM_H
