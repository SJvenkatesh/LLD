#ifndef NOTIFICATIONOBSERVABLE_H
#define NOTIFICATIONOBSERVABLE_H

#include <bits/stdc++.h>
#include "IObservable.h"
#include "../Decorator/INotification.h"

class NotificationObservable : protected IObservable {
    class INotification *notificationMessage;
    public:
    void addObserver(IObserver *ob) override {
        observer.push_back(ob);
    }
    void removeObserver(string name) override {
        for(int i=0;i<observer.size();i++){
            if(observer[i]->getName() == name){
                observer.erase(observer.begin()+i);
                break;
            }
        }
    }

    void setNotification(INotification *no){
        this->notificationMessage = no;
    }

    string notify() override {
        cout<<"Sending Notification "<<endl;
        for(int i=0;i<observer.size();i++){
            observer[i]->update();
        }
        return "SUCESS";
    }

    string getNotification() {
        return notificationMessage->getContent();
    }
};

#endif