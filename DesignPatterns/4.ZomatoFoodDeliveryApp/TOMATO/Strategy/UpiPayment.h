#ifndef UPIPAYMENT_H
#define UPIPAYMENT_H
#include "PaymentStrategy.h"

class UpiPayment  : public PaymentStrategy{
    private:
    string mobileNumber;
    public:
    UpiPayment(string const &mobileNumber) {
        this->mobileNumber = mobileNumber;
    }
    void pay(double amount) override {
        cout<<"Paid amount "<<amount<<" using UPI ( "<<this->mobileNumber<<" )."<<endl;
    }
};

#endif