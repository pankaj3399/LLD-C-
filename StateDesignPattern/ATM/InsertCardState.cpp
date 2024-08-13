#include "InsertCardState.h"
#include "EnterPinState.h"
#include "ReadyState.h"

InsertCardState::InsertCardState(std::string nameC, ATM *atmC)
{
    name = nameC;
    atm = atmC;
}

void InsertCardState::pressStartButton()
{
    std::cout << "Not implemented" << std::endl;
}

void InsertCardState::insertCard(int number, int cvv, std::string date)
{
    std::cout << "Card Inserted" << std::endl;
    this->atm->setState(new EnterPinState("EnterPin", this->atm));
}

void InsertCardState::enterPin(int pin)
{
    std::cout << "Not implemented" << std::endl;
}

void InsertCardState::enterAmount(int amount)
{
    std::cout << "Not implemented" << std::endl;
}

void InsertCardState::dispenseCash()
{
    std::cout << "Not implemented" << std::endl;
}

void InsertCardState::cancel()
{
    std::cout << "Cancelled" << std::endl;
    this->atm->setState(new ReadyState("Ready", this->atm));
}
