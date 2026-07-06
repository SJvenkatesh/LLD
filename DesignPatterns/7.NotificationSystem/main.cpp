#include <bits/stdc++.h>
#include "./Service/NotificationService.h"

using namespace std;

int main() {
    NotificationService *ns = NotificationService::getInstance();
    ns->notificationFormatter("Hello");
    cout<<ns->getNotificationMessage()<<endl;


    class NotificationObservable *no = new NotificationObservable();
    class IObserver *io1= new Logger("venkatesh", no);
    class IObserver *io2= new Logger("rahul", no);
    no->addObserver(io1);
    no->addObserver(io2);
    no->setNotification(ns->notificationMessage);
    no->notify();
    return 0;
}