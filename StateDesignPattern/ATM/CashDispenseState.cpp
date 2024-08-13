#include "CashDispenseState.h"

CashDispenseState::CashDispenseState(std::string nameC, ATM *atmC)
{
    name = nameC;
    atm = atmC;
}

void CashDispenseState::pressStartButton()
{
    std::cout << "Not implemented" << std::endl;
}

void CashDispenseState::insertCard(int number, int cvv, std::string date)
{
    std::cout << "Not implemented" << std::endl;
}

void CashDispenseState::enterPin(int pin)
{
    std::cout << "Not implemented" << std::endl;
}

void CashDispenseState::enterAmount(int amount)
{
    std::cout << "Not implemented" << std::endl;
}

void CashDispenseState::dispenseCash()
{
    std::cout << "Cash dispensed" << std::endl;
    this->atm->setState(new ReadyState("Ready", this->atm));
}

void CashDispenseState::cancel()
{
    std::cout << "Cancelled" << std::endl;
    this->atm->setState(new ReadyState("Ready", this->atm));
}
