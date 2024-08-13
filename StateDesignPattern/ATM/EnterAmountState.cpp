#include "EnterAmountState.h"

EnterAmountState::EnterAmountState(std::string nameC, ATM *atmC)
{
    name = nameC;
    atm = atmC;
}

void EnterAmountState::pressStartButton()
{
    std::cout << "Not implemented" << std::endl;
}

void EnterAmountState::insertCard(int number, int cvv, std::string date)
{
    std::cout << "Not implemented" << std::endl;
}

void EnterAmountState::enterPin(int pin)
{
    std::cout << "Not implemented" << std::endl;
}

void EnterAmountState::enterAmount(int amount)
{
    std::cout << "Amount entered" << std::endl;
    this->atm->setState(new CashDispenseState("CashDispense", this->atm));
}

void EnterAmountState::dispenseCash()
{
    std::cout << "Not implemented" << std::endl;
}

void EnterAmountState::cancel()
{
    std::cout << "Cancelled" << std::endl;
    this->atm->setState(new ReadyState("Ready", this->atm));
}
