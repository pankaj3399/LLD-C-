#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Interface(Abstract class
// with pure virtual function)
class NotificationAlertObserver
{
public:
    virtual void update() = 0;
};

class StockObservable
{
public:
    virtual void add(NotificationAlertObserver *observer) = 0;
    virtual void remove(NotificationAlertObserver *observer) = 0;
    virtual void notifySubscribers() = 0;
    virtual void setStockCount(int data) = 0;
    virtual int getStockCount() = 0;
};

class IphoneObservableImpl : public StockObservable
{
public:
    vector<NotificationAlertObserver *> observersList;
    int stockCount = 0;
    void add(NotificationAlertObserver *observer) { observersList.push_back(observer); }
    void remove(NotificationAlertObserver *observer) { observersList.erase(std::remove(observersList.begin(), observersList.end(), observer), observersList.end()); }
    void notifySubscribers()
    {
        for (auto &observer : observersList)
        {
            observer->update();
        }
    }
    void setStockCount(int data)
    {
        int previousStockCount = stockCount;
        stockCount += data;
        if (previousStockCount == 0)
        {
            notifySubscribers();
        }
    }
    int getStockCount() { return stockCount; }
};

class EmailNotificationObserver : public NotificationAlertObserver
{
public:
    string emailId;
    StockObservable *observable;

    EmailNotificationObserver(string emailId, StockObservable *observable)
    {
        this->emailId = emailId;
        this->observable = observable;
    }

    void update()
    {
        cout << "Sent Email To " << emailId << " " << observable->getStockCount() << endl;
    }
};

class MobileNotificationObserver : public NotificationAlertObserver
{
public:
    string phone;
    StockObservable *observable;

    MobileNotificationObserver(string phone, StockObservable *observable)
    {
        this->phone = phone;
        this->observable = observable;
    }

    void update()
    {
        cout << "Sent Message To " << phone << " " << observable->getStockCount() << endl;
    }
};

// Driver code
int main()
{
    StockObservable *iphoneObservable = new IphoneObservableImpl();

    EmailNotificationObserver *observer1 = new EmailNotificationObserver("abc@gamil.com", iphoneObservable);
    EmailNotificationObserver *observer2 = new EmailNotificationObserver("abcd@gamil.com", iphoneObservable);
    MobileNotificationObserver *observer3 = new MobileNotificationObserver("123456789", iphoneObservable);

    iphoneObservable->add(observer1);
    iphoneObservable->add(observer2);
    iphoneObservable->add(observer3);

    iphoneObservable->setStockCount(10);

    return 0;
}