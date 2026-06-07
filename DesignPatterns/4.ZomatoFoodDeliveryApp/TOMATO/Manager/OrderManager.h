#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include<bits/stdc++.h>
#include "../models/Order.h"

using namespace std;

class OrderManager{
	private:
	vector<Order*> orders;
	static OrderManager *instance;

	OrderManager() {
	}

	public:

	static OrderManager* getInstance() {
		if(!instance) {
			instance = new OrderManager();
		}
		return instance;
	}
	
	void addOrder(Order *order) {
		orders.push_back(order);
	}

	void listOrders() {
		cout << "----------------------Listing all orders -------------------:" << endl;
		for (auto &order : orders) {
			cout << "Order ID: " << order->getOrderId() 
				 << ", Items: " << order->getItems().size() 
				 << ", Total Price: " << order->getTotalAmount() 
				 << endl;
		}
	}
	
	const vector<Order*> getOrders() const {
		return orders;
	} 
	
	bool isEmptyOrder(){
		return orders.size();
	}
	
	void removeOrder(const int orderId) {
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i]->getOrderId() == orderId) {
                orders.erase(orders.begin() + i);
                return;
            }
        }
        cerr << "OrderManager: Order with ID " << orderId << " not found." << endl;
	}
	
    ~OrderManager() {
        cout << "Destroying Order Manager and clearing all orders" << endl;
        for(auto order : orders) {
            delete order;
        }
    }
};

OrderManager* OrderManager::instance = NULL;

#endif