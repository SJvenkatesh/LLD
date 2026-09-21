#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include<bits/stdc++.h>
#include "Order.h"

using namespace std;

class DeliveryOrder : public Order {
	private:
	string userAddress;

	public:
	DeliveryOrder(){
		userAddress = "";
	}
	string getOrderType() const override {
        return "Delivery";
    }
	void setLocation(const string &address){
		this->userAddress = address;
	}
	
	const string getLocation() const {
		return userAddress;
	}
};

#endif