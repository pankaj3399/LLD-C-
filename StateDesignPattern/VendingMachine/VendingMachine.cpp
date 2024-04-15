#include <iostream>
#include <string>
#include <map>

using namespace std;
class State;
class IdleState;
class HasMoneyState;
class SelectionState;
class DispenseState;

enum ItemType
{
    COKE,
    PEPSI,
    JUICE,
    SODA,
};

unordered_map<string, int> coins;

class Item
{
public:
    ItemType itemType;
    int price;

    int getPrice() const { return price; }

    ItemType getItemType() const { return itemType; }

    void setPrice(int value) { price = value; }

    void setItemType(ItemType value) { itemType = value; }
};

class ItemShelf
{
public:
    int code;
    Item *item;
    bool sold;

    int getCode() const { return code; }
    Item *getItem() const { return item; }
    bool isSold() const { return sold; }
    void setSold(bool value) { sold = value; }
    void setItem(Item *value) { item = value; }
    void setCode(int value) { code = value; }
};

class Inventory
{
public:
    vector<ItemShelf *> inventory;
    Inventory(int size)
    {
        inventory.resize(size);
        intializeEmptyInventory();
    }

    void intializeEmptyInventory()
    {
        int startCode = 101;
        for (int i = 0; i < inventory.size(); i++)
        {
            ItemShelf *space = new ItemShelf();
            space->setCode(startCode);
            space->setSold(true);
            inventory[i] = space;
            startCode++;
        }
    }

    vector<ItemShelf *> getInventory()
    {
        return inventory;
    }

    void addItem(Item *item, int codeNumber)
    {

        for (auto itemShelf : inventory)
        {
            if (itemShelf->getCode() == codeNumber)
            {
                if (itemShelf->isSold())
                {
                    itemShelf->setItem(item);
                    itemShelf->setSold(false);
                }
                else
                {
                    cout << "Item is already in this location" << endl;
                }
            }
        }
    }

    Item *getItem(int codeNumber)
    {

        for (auto itemShelf : inventory)
        {
            if (itemShelf->getCode() == codeNumber)
            {
                if (itemShelf->isSold())
                {
                    return NULL;
                }
                else
                {

                    return itemShelf->item;
                }
            }
        }
        // can be updated to throw exception
        return NULL;
    }

    void updateSoldOutItem(int codeNumber)
    {
        for (auto itemShelf : inventory)
        {
            if (itemShelf->getCode() == codeNumber)
            {
                itemShelf->setSold(true);
            }
        }
    }
};

class VendingMachine
{
private:
    State *vendingMachineState;
    Inventory *inventory;
    vector<int> coins;

public:
    VendingMachine(State *state, int inventorySize)
    {
        // Initialize the state and inventory
        vendingMachineState = state;
        inventory = new Inventory(inventorySize);
    }
    void setVendingMachineState(State *state)
    {
        vendingMachineState = state;
    }
    void setInventory(Inventory *inv)
    {
        inventory = inv;
    }
    State *getVendingMachineState()
    {
        return vendingMachineState;
    }
    Inventory *getInventory()
    {
        return inventory;
    }
    vector<int> getCoins()
    {
        return coins;
    }
    void insertCoin(int value) { coins.push_back(value); }
};

class State
{
public:
    virtual void clickOnInsertCoinButton(VendingMachine *machine) = 0;
    virtual void clickOnStartProductSelectionButton(VendingMachine *machine) = 0;
    virtual void insertCoin(VendingMachine *machine, int coin) = 0;
    virtual void chooseProduct(VendingMachine *machine, int codeNumber) = 0;
    virtual int getChange(int returnChangeMoney) = 0;
    virtual Item *dispenseProduct(VendingMachine *machine, int codeNumber) = 0;
    virtual void refundFullMoney(VendingMachine *machine) = 0;
    // see this method what is needed
    virtual void updateInventory(VendingMachine *machine, Item *item, int codeNumber) = 0;
    virtual void print() = 0;
};

class DispenseState : public State
{
public:
    DispenseState(VendingMachine *machine, int codeNumber)
    {
        cout << "Machine is in dispense state" << endl;
        cout << "Dispensing " << codeNumber << endl;
        dispenseProduct(machine, codeNumber);
    }

    void clickOnInsertCoinButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void clickOnStartProductSelectionButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void insertCoin(VendingMachine *machine, int coin) override { cout << "Method is not allowed" << endl; };
    void chooseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    int getChange(int returnChangeMoney) override { cout << "Method is not allowed" << endl; };
    void refundFullMoney(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) override { cout << "Method is not allowed" << endl; };

    Item *dispenseProduct(VendingMachine *machine, int codeNumber) override;
    void print() override
    {
        cout << "I am in dispense state right now!" << endl;
    }
};

class SelectionState : public State
{
public:
    SelectionState()
    {
        cout << " Machine is in selection state" << endl;
    }
    void clickOnInsertCoinButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void clickOnStartProductSelectionButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void insertCoin(VendingMachine *machine, int coin) override { cout << "Method is not allowed" << endl; };
    Item *dispenseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void chooseProduct(VendingMachine *machine, int codeNumber) override;
    void refundFullMoney(VendingMachine *machine) override;
    int getChange(int returnChangeMoney)
    {
        cout << "Returned " << returnChangeMoney << endl;
        return returnChangeMoney;
    }
    void print() override
    {
        cout << "I am in selection state right now!" << endl;
    }
};

class HasMoneyState : public State
{
public:
    HasMoneyState()
    {
        cout << "Machine is in has money state" << endl;
    }
    void clickOnInsertCoinButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void chooseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    int getChange(int returnChangeMoney) override { cout << "Method is not allowed" << endl; };
    Item *dispenseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void clickOnStartProductSelectionButton(VendingMachine *machine)
    {
        machine->setVendingMachineState(new SelectionState());
    }
    void insertCoin(VendingMachine *machine, int coin)
    {
        machine->insertCoin(coin);
    }
    void refundFullMoney(VendingMachine *machine) override;
    void print() override
    {
        cout << "I am in has money state right now!" << endl;
    }
};

class IdleState : public State
{
public:
    IdleState()
    {
        cout << "Machine is in idle state" << endl;
    }
    void clickOnStartProductSelectionButton(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void insertCoin(VendingMachine *machine, int coin) override { cout << "Method is not allowed" << endl; };
    void chooseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    int getChange(int returnChangeMoney) override { cout << "Method is not allowed" << endl; };
    Item *dispenseProduct(VendingMachine *machine, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void refundFullMoney(VendingMachine *machine) override { cout << "Method is not allowed" << endl; };
    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) override { cout << "Method is not allowed" << endl; };
    void clickOnInsertCoinButton(VendingMachine *machine)
    {
        State *state = new HasMoneyState();
        machine->setVendingMachineState(state);
    }
    void print() override
    {
        cout << "I am in idle state right now!" << endl;
    }
};

void HasMoneyState::refundFullMoney(VendingMachine *machine)
{
    machine->setVendingMachineState(new IdleState());
    vector<int> list = machine->getCoins();
    for (auto item : list)
    {
        cout << item << " ";
    }
    cout << endl;
}

void SelectionState::chooseProduct(VendingMachine *machine, int codeNumber)
{
    cout << "Implement here" << endl;
    Item *itemSelected = machine->getInventory()->getItem(codeNumber);

    int paidByUser = 0;
    vector<int> coins = machine->getCoins();
    for (auto item : coins)
    {
        paidByUser += item;
    }
    if (paidByUser < itemSelected->getPrice())
    {
        cout << "Insufficient funds" << endl;
        refundFullMoney(machine);
    }
    else
    {
        if (paidByUser > itemSelected->getPrice())
        {
            getChange(paidByUser - itemSelected->getPrice());
        }
        machine->setVendingMachineState(new DispenseState(machine, codeNumber));
    }
};

void SelectionState::refundFullMoney(VendingMachine *machine)
{
    machine->setVendingMachineState(new IdleState());
    vector<int> list = machine->getCoins();
    for (auto item : list)
    {
        cout << item << " ";
    }
    cout << endl;
};

Item *DispenseState::dispenseProduct(VendingMachine *machine, int codeNumber)
{
    cout << "Dispensing product" << endl;
    Item *item = machine->getInventory()->getItem(codeNumber);
    machine->setVendingMachineState(new IdleState());
    machine->getInventory()->updateSoldOutItem(codeNumber);
    return item;
};

int main()
{
    coins["penny"] = 1;
    coins["nickel"] = 5;
    coins["dime"] = 10;
    coins["quarter"] = 25;
    State *state = new IdleState();
    VendingMachine *machine = new VendingMachine(state, 10);
    cout << "filling inventory...." << endl;
    int codeNumber = 101;
    for (int i = 0; i < 10; i++)
    {
        Item *item = new Item();
        if (i < 3)
        {
            item->setItemType(COKE);
            item->setPrice(10);
        }
        else if (i < 6)
        {
            item->setItemType(PEPSI);
            item->setPrice(20);
        }
        else
        {
            item->setItemType(SODA);
            item->setPrice(30);
        }
        machine->getInventory()->addItem(item, codeNumber);
        codeNumber++;
    }

    cout << "displaying inventory...." << endl;

    vector<ItemShelf *> filledInv = machine->getInventory()->getInventory();
    for (auto item : filledInv)
    {
        cout << "Code : " << item->getCode() << " "
             << "Price: " << item->getItem()->getPrice() << " "
             << "Type:" << item->getItem()->getItemType() << " "
             << "Sold: " << item->isSold() << endl;
    }
    cout << "clicking on insert coin button..." << endl;
    machine->getVendingMachineState()->print();
    machine->getVendingMachineState()->clickOnInsertCoinButton(machine);
    machine->getVendingMachineState()->insertCoin(machine, coins["nickel"]);
    machine->getVendingMachineState()->insertCoin(machine, coins["quarter"]);
    machine->getVendingMachineState()->print();
    machine->getVendingMachineState()->clickOnStartProductSelectionButton(machine);
    machine->getVendingMachineState()->print();
    machine->getVendingMachineState()->chooseProduct(machine, 102);
    cout << "displaying inventory...." << endl;

    vector<ItemShelf *> filledIn = machine->getInventory()->getInventory();
    for (auto item : filledIn)
    {
        cout << "Code : " << item->getCode() << " "
             << "Price: " << item->getItem()->getPrice() << " "
             << "Type:" << item->getItem()->getItemType() << " "
             << "Sold: " << item->isSold() << endl;
    }
    return 0;
}