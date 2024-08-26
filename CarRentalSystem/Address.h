#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

using namespace std;

class Address
{
public:
    int id;
    string street;
    int zipcode;
    double latitude;
    double longitude;
    Address(int ids, string st, int zip, double lat, double lng);
};

#endif // ADDRESS_H