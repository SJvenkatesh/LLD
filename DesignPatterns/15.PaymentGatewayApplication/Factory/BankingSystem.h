#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <bits/stdc++.h>

using namespace std;

class BankingSystem {
    public:
    virtual void processPayment(double amount) = 0;
};

#endif