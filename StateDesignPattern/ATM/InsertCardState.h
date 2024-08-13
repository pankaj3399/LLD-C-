#ifndef INSERTCARDSTATE_H
#define INSERTCARDSTATE_H

#include "ATMState.h"
#include "ATM.h"
#include "EnterPinState.h"

class InsertCardState : public ATMState
{
public:
    InsertCardState(std::string nameC, ATM *atmC);
    void pressStartButton() override;
    void insertCard(int number, int cvv, std::string date) override;
    void enterPin(int pin) override;
    void enterAmount(int amount) override;
    void dispenseCash() override;
    void cancel() override;
};

#endif // INSERTCARDSTATE_H
