#include "ATM.h"
#include "ReadyState.h"

int main()
{
    ATM *atm = new ATM(1);
    atm->setState(new ReadyState("Ready", atm));
    atm->pressStartButton();
    atm->insertCard(123456, 123, "12/25");
    atm->enterPin(1234);
    atm->enterAmount(500);
    atm->dispenseCash();
    // atm->cancel();

    return 0;
}
