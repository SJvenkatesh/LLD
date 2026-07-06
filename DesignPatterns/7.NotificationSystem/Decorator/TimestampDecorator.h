#ifndef TIMESTAMPDECORATOR_H
#define TIMESTAMPDECORATOR_H

#include "IDecoratorNotification.h"
#include "../Utils/TimeUtils.h"

#include <bits/stdc++.h>

using namespace std;

class TimestampDecorator : public IDecoratorNotification {
	public:
	TimestampDecorator(INotification *notification)
		:IDecoratorNotification(notification) {}
	string getContent() override {
		string message = notification->getContent();
		string updateMessage = "[ " + TimeUtils::getCurrentTime() + " ] " + message;
		// notification->setMessage(updateMessage); // simple decorator does'nt modify the actual message it only update 
		return updateMessage;
	}
};

#endif