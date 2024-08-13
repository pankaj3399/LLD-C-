#include "EnterPinState.h"

EnterPinState::EnterPinState(std::string nameC, ATM *atmC)
{
    name = nameC;
    atm = atmC;
}

void EnterPinState::pressStartButton()
{
    std::cout << "Not implemented" << std::endl;
}

void EnterPinState::insertCard(int number, int cvv, std::string date)
{
    std::cout << "Not implemented" << std::endl;
}

void EnterPinState::enterPin(int pin)
{
    std::cout << "Pin entered" << std::endl;
    this->atm->setState(new EnterAmountState("EnterAmount", this->atm));
}

void EnterPinState::enterAmount(int amount)
{
    std::cout << "Not implemented" << std::endl;
}

void EnterPinState::dispenseCash()
{
    std::cout << "Not implemented" << std::endl;
}

void EnterPinState::cancel()
{
    std::cout << "Cancelled" << std::endl;
    this->atm->setState(new ReadyState("Ready", this->atm));
}
