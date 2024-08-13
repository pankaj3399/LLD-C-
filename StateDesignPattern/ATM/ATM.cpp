#include "ATM.h"

ATM::ATM(int ids)
{
    id = ids;
}

void ATM::setState(ATMState *atmStat)
{
    atmState = atmStat;
}

void ATM::pressStartButton()
{
    this->atmState->pressStartButton();
}

void ATM::insertCard(int number, int cvv, std::string date)
{
    this->atmState->insertCard(number, cvv, date);
}

void ATM::enterPin(int pin)
{
    this->atmState->enterPin(pin);
}

void ATM::enterAmount(int amount)
{
    this->atmState->enterAmount(amount);
}

void ATM::dispenseCash()
{
    this->atmState->dispenseCash();
}

void ATM::cancel()
{
    this->atmState->cancel();
}
