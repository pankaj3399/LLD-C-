#include <iostream>

using namespace std;

class PaymentStrategy
{
public:
    virtual ~PaymentStrategy() {};
    virtual void processPayment(int amount) = 0;
};

class CreditCardPayment : public PaymentStrategy
{
public:
    void processPayment(int amount) override
    {
        cout << "Amount: " << amount << " is charged via credit card" << endl;
    }
};

class PaypalPayment : public PaymentStrategy
{
public:
    void processPayment(int amount) override
    {
        cout << "Amount: " << amount << " is charged via paypal" << endl;
    }
};

class PaymentStrategyFactory
{
public:
    static PaymentStrategy *createPaymentStrategy(const std::string &payment)
    {
        if (payment == "CreditCard")
        {
            return new CreditCardPayment();
        }
        else if (payment == "Paypal")
        {
            return new PaypalPayment();
        }
        else
        {
            return new CreditCardPayment();
        }
    }
};

class PaymentProcessor
{
private:
    PaymentStrategy *paymentStrategy;

public:
    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(const std::string &payment)
    {
        if (paymentStrategy)
        {
            delete paymentStrategy;
        }
        paymentStrategy = PaymentStrategyFactory::createPaymentStrategy(payment);
    }
    void processPayment(int amount)
    {
        if (paymentStrategy)
        {
            paymentStrategy->processPayment(amount);
        }
        else
        {
            cerr << "Payment strategy not set." << endl;
        }
    }

    ~PaymentProcessor()
    {
        if (paymentStrategy)
        {
            delete paymentStrategy; // Clean up the strategy instance
        }
    }
};

int main()
{
    PaymentProcessor processor;

    // Use the factory to create payment strategies
    processor.setPaymentStrategy("CreditCard");
    processor.processPayment(100.0);

    processor.setPaymentStrategy("Paypal");
    processor.processPayment(50.0);
    return 0;
}