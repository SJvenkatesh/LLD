#ifndef ICHANNEL_H
#define ICHANNEL_H

#include <bits/stdc++.h>
using namespace std;

#include "ISubscriber.h"

class IChannel {
	public:
	virtual void subscribe(ISubscriber* subscriber) = 0;
	virtual void unsubscribe(ISubscriber* subscriber) = 0;
	virtual void notifySubscriber(const string &title) = 0;
	virtual ~IChannel() {}
};

#endif