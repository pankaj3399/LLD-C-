#include "ReadyState.h"

ReadyState::ReadyState(std::string nameC, ATM *atmC)
{
    name = nameC;
    atm = atmC;
}

void ReadyState::pressStartButton()
{
    std::cout << "Press Start" << std::endl;
    this->atm->setState(new InsertCardState("InsertCard", this->atm));
}

void ReadyState::insertCard(int number, int cvv, std::string date)
{
    std::cout << "Not implemented" << std::endl;
}

void ReadyState::enterPin(int pin)
{
    std::cout << "Not implemented" << std::endl;
}

void ReadyState::enterAmount(int amount)
{
    std::cout << "Not implemented" << std::endl;
}

void ReadyState::dispenseCash()
{
    std::cout << "Not implemented" << std::endl;
}

void ReadyState::cancel()
{
    std::cout << "Not implemented" << std::endl;
}
