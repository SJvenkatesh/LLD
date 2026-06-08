#ifndef CHANNEL_H
#define CHANNEL_H

#include <bits/stdc++.h>
using namespace std;

#include "../Interfaces/ISubscriber.h"
#include "../Interfaces/IChannel.h"

class Channel : public IChannel {
    private:
    string name;
    vector<ISubscriber*> subscribers;
    public:
    Channel(const string name) {
        this->name = name;
    }
    const string getName() const {
        return name;
    }
    void subscribe(ISubscriber* subscriber) override {
        subscribers.push_back(subscriber);
    }
    void unsubscribe(ISubscriber* subscriber) override {
    	for(int i=0;i<subscribers.size(); i++) {
    		if(subscriber->getName() == subscribers[i]->getName()){
    			subscribers.erase(subscribers.begin()+i);
    			return;
    		}
    	
    	}
  
    }
    void notifySubscriber(const string &title) {
        for (ISubscriber* subscriber : subscribers) {
            subscriber->update(title);
        }
    }
};

#endif