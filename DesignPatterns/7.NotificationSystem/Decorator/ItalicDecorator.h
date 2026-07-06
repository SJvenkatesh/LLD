#ifndef ITALICDECORATOR_H
#define ITALICDECORATOR_H

#include "IDecoratorNotification.h"
#include "INotification.h"

#include <bits/stdc++.h>

using namespace std;

class ItalicDecorator : public IDecoratorNotification {
	public:
	ItalicDecorator(INotification *notification) 
		:IDecoratorNotification(notification) {}
	string getContent() override {
		string message = notification->getContent();
		string updateMessage = "Italic " + message;
		return updateMessage;
	}
};

#endif