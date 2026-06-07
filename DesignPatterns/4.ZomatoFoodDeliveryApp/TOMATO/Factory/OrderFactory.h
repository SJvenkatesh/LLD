#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "../models/Order.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../models/User.h"
#include "../models/Restaurant.h"
#include "../models/Cart.h"
#include "../Strategy/PaymentStrategy.h"

using namespace std;

class OrderFactory {
    protected:
	Order *order;
	public:
    OrderFactory(const string &orderType) {
        if (orderType == "Delivery") {
            order = new DeliveryOrder();
        } else if (orderType == "Pickup") {
            order = new PickupOrder();
        } else {
            cerr << "Invalid order type: " << orderType << ". Order not created." << endl;
            order = NULL;
        }
    }
	virtual void createOrder(const User *user, const Cart *cart, const PaymentStrategy *ps, string orderType = "") = 0;
};

#endif