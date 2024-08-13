#ifndef ATMSTATE_H
#define ATMSTATE_H

#include <string>
#include <iostream>

class ATM;

class ATMState
{
public:
    std::string name;
    ATM *atm;
    virtual void pressStartButton() = 0;
    virtual void insertCard(int number, int cvv, std::string date) = 0;
    virtual void enterPin(int pin) = 0;
    virtual void enterAmount(int amount) = 0;
    virtual void dispenseCash() = 0;
    virtual void cancel() = 0;
};

#endif // ATMSTATE_H
