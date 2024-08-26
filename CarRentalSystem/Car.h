#ifndef CAR_H
#define CAR_H
#include <string>
#include "Address.h"

using namespace std;

enum class Type
{
    SEDAN,
    SUV,
    HATCHBACK
};

enum class Status
{
    BOOKED,
    RUNNING,
    VACANT,
};

class Car
{
public:
    string name;
    string brand;
    Address *location;
    int price; // can be omitted from here and a separate pricing strategy + manager can be there
    Type type;
    Status status;
    Car(string nm, string br, Address *addr, int pr, Type ty);
    // void bookVehicle();
    // void updateCar();
};

#endif