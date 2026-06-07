#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "OrderFactory.h"
#include "../models/Order.h"

using namespace std;

class ScheduledOrder : public OrderFactory {
	public:
	void createOrder(const User *user, const Cart *cart, const PaymentStrategy *ps, string orderType = "") override {
		cout<<"Creating Scheduled order for user "<< user->getName()<<endl;
		if(!order){
			cerr<<"Select correct order type"<<endl;
		}
		
		if(!cart->isEmpty()){
			cerr<<"Please select Restarurant or Cart to genrate order"<<endl;
		}
		order->setRestaurant(cart->getRestaurant());
		for(auto item : cart->getItems()) {
			order->addItem(item);
		}
		order->setUser(user);
		order->selectPaymentStrategy(ps);
		order->setScheduled(TimeUtils::getCurrentTime() + " Scheduled for 1hour"); // Schedule for 1 hour later
	}
};

#endif