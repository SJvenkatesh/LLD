#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H
#include "PaymentStrategy.h"

using namespace std;

class CardPayment  : public PaymentStrategy{
    string cardNumber;
	public:
    CardPayment(const string &cardNumber) {
        this->cardNumber = cardNumber;
    }
	void pay(double amount) override {
        cout<<"Paid amount "<<amount<<" using Card ( "<< this->cardNumber<<" )."<<endl;
    }
};

#endif
