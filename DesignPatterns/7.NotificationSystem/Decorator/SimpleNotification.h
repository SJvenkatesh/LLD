#ifndef SIMPLENOTIFICATION_H
#define SIMPLENOTIFICATION_H
#include<bits/stdc++.h>
#include "INotification.h"

using namespace std;

class SimpleNotification : public INotification {
    string message;
    public:
    SimpleNotification(string message) {
        this->message = message;
    }
    string getContent() override {
        cout << "Simple Notification: " << message << endl;
        return message;
    }
};

#endif