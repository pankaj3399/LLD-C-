#include <iostream>

using namespace std;

class OrderProcessingTemplate
{
public:
    virtual ~OrderProcessingTemplate() {}
    void processOrder()
    {
        verifyOrder();
        assignDP();
        trackDelivery();
    }

    virtual void verifyOrder() = 0;
    virtual void trackDelivery() = 0;
    virtual void assignDP() = 0;
};

class LocalOrderProcessingTemplate : public OrderProcessingTemplate
{
public:
    void verifyOrder()
    {
        cout << "Verifying Local Order Processing" << endl;
    }
    void assignDP()
    {
        cout << "Assigning Local Order Processing" << endl;
    }
    void trackDelivery()
    {
        cout << "Tracking Local Order Processing" << endl;
    }
};

class InternationalOrderProcessingTemplate : public OrderProcessingTemplate
{
public:
    void verifyOrder()
    {
        cout << "Verifying International Order Processing" << endl;
    }
    void assignDP()
    {
        cout << "Assigning International Order Processing" << endl;
    }
    void trackDelivery()
    {
        cout << "Tracking International Order Processing" << endl;
    }
};

int main()
{

    OrderProcessingTemplate *local = new LocalOrderProcessingTemplate();
    local->verifyOrder();

    delete local;

    return 0;
}