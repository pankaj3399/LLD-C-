#ifndef ENTERPINSTATE_H
#define ENTERPINSTATE_H

#include "ATMState.h"
#include "ATM.h"
#include "EnterAmountState.h"

class EnterPinState : public ATMState
{
public:
    EnterPinState(std::string nameC, ATM *atmC);
    void pressStartButton() override;
    void insertCard(int number, int cvv, std::string date) override;
    void enterPin(int pin) override;
    void enterAmount(int amount) override;
    void dispenseCash() override;
    void cancel() override;
};

#endif // ENTERPINSTATE_H
