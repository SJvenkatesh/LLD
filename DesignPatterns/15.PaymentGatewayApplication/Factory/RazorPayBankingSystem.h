#ifndef RAZORPAYBANKINGSYSTEM_H
#define RAZORPAYBANKINGSYSTEM_H

#include <bits/stdc++.h>
#include "./BankingSystem.h"

using namespace std;

class RazorpayBankingSystem : public BankingSystem {
    public:
    void processPayment(double amount) override {
        cout<<"Processed Razor payment : "<<amount<<endl;
    }
};

#endif