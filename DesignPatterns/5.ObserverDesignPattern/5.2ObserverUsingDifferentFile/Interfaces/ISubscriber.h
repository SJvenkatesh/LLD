#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include <bits/stdc++.h>
using namespace std;

class ISubscriber {
    public:
    virtual void update(const string &title) = 0;
    virtual const string getName() const = 0;
    virtual ~ISubscriber() {}
};

#endif