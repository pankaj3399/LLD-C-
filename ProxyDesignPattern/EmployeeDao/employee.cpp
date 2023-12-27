#include <iostream>
#include <string>

using namespace std;

class EmployeeDao
{
public:
    virtual void create(string client, string name) = 0;
    virtual void del(string client, int id) = 0;
    virtual void get(string client, int id) = 0;
};

class EmployeeDaoImpl : public EmployeeDao
{
public:
    void create(string client, string name)
    {
        cout << "Created " << name << endl;
    }

    void del(string client, int id)
    {
        cout << "Deleted " << id << endl;
    }

    void get(string client, int id)
    {
        cout << "Get " << id << endl;
    }
};

class EmployeeDaoImplProxy : public EmployeeDao
{
public:
    EmployeeDao *employeeDao;

    EmployeeDaoImplProxy()
    {
        employeeDao = new EmployeeDaoImpl();
    }
    void create(string client, string name)
    {
        if (client == "USER")
        {
            cout << "Not allowed to create " << name << endl;
            return;
        }
        employeeDao->create(client, name);
    }

    void del(string client, int id)
    {
        if (client == "USER")
        {
            cout << "Not allowed to delete " << id << endl;
            return;
        }
        employeeDao->del(client, id);
    }

    void get(string client, int id)
    {
        employeeDao->get(client, id);
    }
};

int main()
{
    EmployeeDaoImplProxy *proxy = new EmployeeDaoImplProxy();
    proxy->create("USER", "Pankaj");
    proxy->create("ADMIN", "Pankaj2");
    return 0;
}