#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include <bits/stdc++.h>
#include "IObserver.h"

using namespace std;

class IObservable {
    protected:
    vector<IObserver*> observer;
    public:
    virtual void addObserver(IObserver *o) = 0;
    virtual void removeObserver(string name) = 0;
    virtual string notify() = 0;    
};

#endif