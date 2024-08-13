#ifndef CASHDISPENSESTATE_H
#define CASHDISPENSESTATE_H

#include "ATMState.h"
#include "ATM.h"
#include "ReadyState.h"

class CashDispenseState : public ATMState
{
public:
    CashDispenseState(std::string nameC, ATM *atmC);
    void pressStartButton() override;
    void insertCard(int number, int cvv, std::string date) override;
    void enterPin(int pin) override;
    void enterAmount(int amount) override;
    void dispenseCash() override;
    void cancel() override;
};

#endif // CASHDISPENSESTATE_H
