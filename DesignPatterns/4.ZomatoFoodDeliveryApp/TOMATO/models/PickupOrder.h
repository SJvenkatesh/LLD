#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include<bits/stdc++.h>
#include "Order.h"

using namespace std;

class PickupOrder : public Order {
	private:
    string restaurantAddress;	public:
	
    PickupOrder(){
		restaurantAddress = "";	
	}
    string getOrderType() const override {
        return "Pickup";
    }
    void setRestaurantAddress(const string &restaurantAddress){
        this->restaurantAddress = restaurantAddress;
    }
    const string getRestaurantAddress() const {
        return restaurantAddress;
    }
};

#endif