#include "./Models/Channel.h"
#include "./Models/Subscriber.h"

#include <bits/stdc++.h>
using namespace std;

int main() {
    Channel* channel = new Channel("CoderArmy");

    Subscriber* subs1 = new Subscriber("Varun", channel);
    Subscriber* subs2 = new Subscriber("Tarun", channel);

    channel->subscribe(subs1);
    channel->subscribe(subs2);

    channel->notifySubscriber("Observer Pattern Tutorial");

    channel->unsubscribe(subs1);

    channel->notifySubscriber("Decorator Pattern Tutorial");

    delete subs1;
    delete subs2;
    delete channel;

    return 0;
}