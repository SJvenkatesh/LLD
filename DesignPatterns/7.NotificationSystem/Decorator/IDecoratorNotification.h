#ifndef IDECORATORNOTIFICATION_H
#define IDECORATORNOTIFICATION_H
#include <bits/stdc++.h>
#include "INotification.h"

using namespace std;

class IDecoratorNotification : public INotification {
    protected:
    INotification *notification ;
    public:
    IDecoratorNotification(INotification *notification) {
        this->notification = notification;
    }
};

#endif