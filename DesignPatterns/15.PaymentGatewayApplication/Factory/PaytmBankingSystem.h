#ifndef PAYTMBANKINGSYSTEM_H
#define PAYTMBANKINGSYSTEM_H

#include <bits/stdc++.h>
#include "./BankingSystem.h"

using namespace std;

class PaytmBankingSystem : public BankingSystem {
    public:
    void processPayment(double amount) override {
        cout<<"Processed Paytm payment : "<<amount<<endl;
    }
};


#endif