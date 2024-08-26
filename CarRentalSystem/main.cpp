#include <iostream>
#include "Address.h"
#include "Car.h"
#include "User.h"
#include <vector>
#include <map>

using namespace std;

class Booking {
    public:
    User* user;
    Car* car;
    Address* pickupAddress;
    Address* dropAddress;
    int price;
    Booking(User* user, Car* car, Address* pickupAddress, Address* dropAddress, int price){
        this->user = user;
        this->car = car;
        this->pickupAddress = pickupAddress;
        this->dropAddress = dropAddress;
        this->price = price;
    }

};

class CarReservationManager
{
public:
    vector<Car *> cars;
    vector<User *> user;
    map<int, vector<Car *> > listCars;
    vector<Car *> getCarsByZip(int zipcode)
    {
        vector<Car *> v;
        if (listCars.find(zipcode) != listCars.end())
        {
            v = listCars[zipcode];
        }
        return v;
    }
    void addCar(Car *car)
    {
        cars.push_back(car);
        listCars[car->location->zipcode].push_back(car);
    }

    void bookCar(User* user, Car* car,Address* paddress, Address* daddress){
        if(car->status == Status::VACANT){
            // charge client
            Booking *booking = new Booking(user,car,paddress,daddress, car->price);
            auto it = find(listCars[paddress->zipcode].begin(),listCars[paddress->zipcode].end(),car);
            if(it!= listCars[paddress->zipcode].end()){
                listCars[paddress->zipcode].erase(it);
            }
            car->status = Status::RUNNING; // do in book method of car
            cout << "User " << user->name << " has booked " << car->name << " successfully" << endl;
             //send confirmation
        } else {
            cout << car->name << " is already booked" << endl;
        }
    }    
};

Address::Address(int ids, string st, int zip, double lat, double lng)
{
    id = ids;
    street = st;
    zipcode = zip;
    latitude = lat;
    longitude = lng;
}



Car::Car(string nm, string br, Address *addr, int pr, Type ty)
{
    name = nm;
    brand = br;
    location = addr;
    price = pr;
    type = ty;
    status = Status::VACANT;
}


User::User(int ids, string nm, string em, string pn, string lic)
{
    id = ids;
    name = nm;
    email = em;
    pan = pn;
    license = lic;
}

void User::setAddress(Address *addr)
{
    address = addr;
}



int main()
{
    cout << "Hi" << endl;
    Address *addr = new Address(1, "ABC Street NY", 12345, 100.1, 100.2);
    Address *addr2 = new Address(2, "DEF Street NY", 12346, 100.2, 100.3);
    Address *addr3 = new Address(3, "ABC Street Dalal", 12345, 100.3, 100.3);
    Car *car1 = new Car("Celerio 1", "Maruti", addr, 1000, Type::HATCHBACK);
    Car *car2 = new Car("Swift", "Maruti", addr2, 1500, Type::SEDAN);
    CarReservationManager *manager = new CarReservationManager();
    manager->addCar(car1);
    manager->addCar(car2);

    User *user = new User(1, "Pankaj", "pankaj@gmail.com", "ABCD", "DEFG");


    user->setAddress(addr3);
    vector<Car *> availableCars = manager->getCarsByZip(user->address->zipcode);
    for (int i = 0; i < availableCars.size(); i++)
    {
        cout << availableCars[i]->name << " is available at price " << availableCars[i]->price << endl;
    }
    manager->bookCar(user, availableCars[0],addr3,addr2);
    // manager->bookCar(user, availableCars[0],addr3,addr2);
    //  availableCars = manager->getCarsByZip(user->address->zipcode);
    // for (int i = 0; i < availableCars.size(); i++)
    // {
    //     cout << availableCars[i]->name << " is available at price " << availableCars[i]->price << endl;
    // }

    return 0;
}