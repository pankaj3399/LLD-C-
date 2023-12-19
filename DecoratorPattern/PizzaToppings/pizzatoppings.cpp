#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BasePizza
{
public:
    virtual int cost() = 0;
};

class Farmhouse : public BasePizza
{
public:
    int cost()
    {
        return 110;
    }
};

class VeggieDelight : public BasePizza
{
public:
    int cost()
    {
        return 120;
    }
};

class Margarita : public BasePizza
{
public:
    int cost()
    {
        return 100;
    }
};

class ToppingDecorator : public BasePizza
{
};

class ExtraCheeze : public BasePizza
{
public:
    BasePizza *pizza;
    ExtraCheeze(BasePizza *bpizza)
    {
        pizza = bpizza;
    }
    int cost()
    {
        return this->pizza->cost() + 10;
    }
};

class ExtraMushroom : public BasePizza
{
public:
    BasePizza *pizza;
    ExtraMushroom(BasePizza *bpizza)
    {
        pizza = bpizza;
    }
    int cost()
    {
        return this->pizza->cost() + 20;
    }
};

// Driver code
int main()
{
    BasePizza *pizza = new ExtraMushroom(new VeggieDelight());
    cout << pizza->cost() << endl;
    return 0;
}