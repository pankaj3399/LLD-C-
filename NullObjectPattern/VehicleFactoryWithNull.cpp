#include <iostream>
#include <string>

using namespace std;

class VehicleInterface
{
public:
    virtual int getCapacity() = 0;
};

class Bike : public VehicleInterface
{
public:
    int getCapacity()
    {
        return 40;
    }
};

class NullObject : public VehicleInterface
{
public:
    int getCapacity()
    {
        return 0;
    }
};

class VehicleFactory
{
public:
    VehicleInterface *getVehicle(string type)
    {
        if (type == "Bike")
        {
            return new Bike();
        }

        return new NullObject();
    }
};

int main()
{
    VehicleFactory *factory = new VehicleFactory();
    cout << factory->getVehicle("Car")->getCapacity() << endl;
    cout << factory->getVehicle("Bike")->getCapacity() << endl;
    return 0;
}