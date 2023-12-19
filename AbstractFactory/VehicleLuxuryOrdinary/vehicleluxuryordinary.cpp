#include <iostream>
#include <string>

using namespace std;

class VehicleInterface
{
public:
    virtual void avg() = 0;
};

class VehicleFactoryInterface
{
public:
    virtual VehicleInterface *getVehicle(string name) = 0;
};

class BMW : public VehicleInterface
{
public:
    void avg()
    {
        cout << "BMW avg" << endl;
    }
};

class Audi : public VehicleInterface
{
public:
    void avg()
    {
        cout << "Audi avg" << endl;
    }
};

class Swift : public VehicleInterface
{
public:
    void avg()
    {
        cout << "Swift avg" << endl;
    }
};

class Alto : public VehicleInterface
{
public:
    void avg()
    {
        cout << "Alto avg" << endl;
    }
};

class OrdinaryFactory : public VehicleFactoryInterface
{
public:
    VehicleInterface *getVehicle(string name)
    {
        if (name == "Alto")
            return new Alto();
        else if (name == "Swift")
            return new Swift();
        else
            return new Alto();
    }
};

class LuxuryFactory : public VehicleFactoryInterface
{
public:
    VehicleInterface *getVehicle(string name)
    {
        if (name == "BMW")
            return new BMW();
        else if (name == "Audi")
            return new Audi();
        return new BMW();
    }
};

class FinalFactory
{
public:
    VehicleFactoryInterface *getVehicleFactory(string name)
    {
        if (name == "Luxury")
        {
            return new LuxuryFactory();
        }
        else
        {
            return new OrdinaryFactory();
        }
    }
};

int main()
{
    FinalFactory *factory = new FinalFactory();
    factory->getVehicleFactory("Luxury")->getVehicle("BMW")->avg();
}