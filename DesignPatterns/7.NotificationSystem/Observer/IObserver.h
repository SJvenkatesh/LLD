#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <bits/stdc++.h>

using namespace std;

class IObserver {
    public:
    virtual string getName() = 0;
    virtual void update() = 0;
};

#endif