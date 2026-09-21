#ifndef NETBANKING_H
#define NETBANKING_H
#include "PaymentStrategy.h"

class NetBanking  : public PaymentStrategy{
    string bankName;
	public:
    NetBanking(string const &bankName) {
        this->bankName = bankName;

    }
	void pay(double amount) override {
        cout<<"Paid amount "<<amount<<" using NetBanking ( "<<this->bankName<<" )."<<endl;
    }
}

#endif