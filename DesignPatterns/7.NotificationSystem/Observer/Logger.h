#ifndef LOGGER_H
#define LOGGER_H

#include <bits/stdc++.h>
#include "NotificationObservable.h"

using namespace std;

class Logger : public IObserver {
    class  NotificationObservable *no;
    string name;
    public:
    Logger(string name, NotificationObservable *no){
        this->name = name;
        this->no = no;
    }
    string getName(){
        return name;
    }
    void update(){
        cout<<"Notification reached "<<endl;
        string message = no->getNotification();
        cout<<"Message : "<<message<<endl;
    }
};

#endif