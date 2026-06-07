#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

class PaymentStrategy{
	public:
	virtual void pay(double amount) = 0;
    ~PaymentStrategy() {
        cout<<"Destroying Payment Strategy"<<endl;
    }
};

#endif