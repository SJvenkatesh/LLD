#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H


#include "../Decorator/INotification.h"
#include "../Decorator/IDecoratorNotification.h"
#include "../Decorator/ItalicDecorator.h"
#include "../Decorator/SimpleNotification.h"
#include "../Decorator/TimestampDecorator.h"
#include "../Observer/IObservable.h"
#include "../Observer/Logger.h"

#include <bits/stdc++.h>

using namespace std;

class NotificationService {
	NotificationObservable *no;
	static NotificationService *instance;
	
	NotificationService(){
		cout<< "NotificationService Constructor called. New Object Created."<<endl;
	}
	public:
	INotification *notificationMessage;
	static NotificationService *getInstance(){
		if(!instance){
			return new NotificationService();
		}
		return instance;
	}


	string notificationFormatter(string message, vector<string> decorators = {"italic", "timestamp"}) {
		cout<<"Message received: "<<message<<endl;
		notificationMessage = new SimpleNotification(message);
		for (const auto& decorator : decorators) {
			if (decorator == "italic") {
				notificationMessage = new ItalicDecorator(notificationMessage);
			}
			else if (decorator == "timestamp") {
				notificationMessage = new TimestampDecorator(notificationMessage);
			}
		}
		cout<<notificationMessage->getContent()<<endl;
		return notificationMessage->getContent();
	}

	string getNotificationMessage(){
		return notificationMessage->getContent();
	}

	void setNotificationObservable(NotificationObservable *no){
		this->no = no;
	}

	void notify(string type = "logger") {
		no->setNotification(notificationMessage);
		no->notify();
	}

};

NotificationService* NotificationService::instance = NULL;

#endif