#ifndef READYSTATE_H
#define READYSTATE_H

#include "ATMState.h"
#include "ATM.h"
#include "InsertCardState.h"

class ReadyState : public ATMState
{
public:
    ReadyState(std::string nameC, ATM *atmC);
    void pressStartButton() override;
    void insertCard(int number, int cvv, std::string date) override;
    void enterPin(int pin) override;
    void enterAmount(int amount) override;
    void dispenseCash() override;
    void cancel() override;
};

#endif // READYSTATE_H
