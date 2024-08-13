#ifndef ENTERAMOUNTSTATE_H
#define ENTERAMOUNTSTATE_H

#include "ATMState.h"
#include "ATM.h"
#include "CashDispenseState.h"

class EnterAmountState : public ATMState
{
public:
    EnterAmountState(std::string nameC, ATM *atmC);
    void pressStartButton() override;
    void insertCard(int number, int cvv, std::string date) override;
    void enterPin(int pin) override;
    void enterAmount(int amount) override;
    void dispenseCash() override;
    void cancel() override;
};

#endif // ENTERAMOUNTSTATE_H
