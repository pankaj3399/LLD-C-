#ifndef USER_H
#define USER_H
#include <string>

#include "Address.h"

using namespace std;

class User
{
public:
    int id;
    string name;
    string email;
    string pan;
    string license;
    Address *address;
    User(int ids, string nm, string em , string pn, string lic);
    void setAddress( Address *adds);
};

#endif // USER_H