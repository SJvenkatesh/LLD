#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <bits/stdc++.h>
using namespace std;

#include "../Interfaces/ISubscriber.h"
#include "Channel.h"


class Subscriber : public ISubscriber {
    private:
    string name;
    Channel* channel;
    public:
    Subscriber(const string name, Channel* channel) {
        this->name = name;
        this->channel = channel;
    }
    const string getName() const {
        return name;
    }
    void update(const string &title) override {
        cout << "Hey " << name << ", new video uploaded: " << title << " from Channel" << channel->getName() << endl;
    }
};

#endif