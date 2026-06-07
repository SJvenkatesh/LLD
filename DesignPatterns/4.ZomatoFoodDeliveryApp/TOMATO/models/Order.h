#ifndef ORDER_H
#define ORDER_H


#include<bits/stdc++.h>

#include "Restaurant.h"
#include "MenuItem.h"
#include "User.h"
#include "../Strategy/PaymentStrategy.h"

using namespace std;

class Order {
	protected:
	int orderId;
	static int nextOrderId;
	Restaurant *restaurant;
	vector<MenuItem> items;
	User *user;
	PaymentStrategy *paymentStrategy;
	double total;
	string scheduled;
	bool payed;
	public:
	Order(){
		restaurant = NULL;
		paymentStrategy = NULL;
		orderId = ++nextOrderId;
		user = NULL;
		total = 0;
		scheduled = "";
	}
	virtual ~Order() = default;
	virtual string getOrderType() const = 0;
	int getOrderId() const {
		return orderId;
	}
	void setUser(User *user){
		this->user = user;
	}
	
	User* getUser() const{
		return user;
	}
	
	void setRestaurant( Restaurant *restaurant){
		if(!user){
			cerr<<"Select User first then add restaurant";
		}
		this->restaurant = restaurant;
	}
	//first const : the returned Restaurant cannot be modified through the pointer
	//second const : the function itself does not modify the object it belongs to
	const Restaurant* getRestaurant() const{
		return restaurant;
	}
	
	void addItem(const MenuItem &item){
		if(!restaurant){
			cerr<<"Select restaurant first then add items";
		}
		items.push_back(item);
		total += item.getPrice();
	}

	// void removeItem(const MenuItem &item){
	// 	auto it = find(items.begin(), items.end(), item);
	// 	if(it != items.end()){
	// 		total -= it->getPrice();
	// 		items.erase(it);
	// 	}
	// }
	
	void selectPaymentStrategy(PaymentStrategy *ps){
		this->paymentStrategy = ps;
	}
	
	void setScheduledTime(const string &time) {
		scheduled = time;
	}
	
	double getTotalAmount(){
		return total;
	}

	vector<MenuItem> getItems() const {
		return items;
	}
	
	void processPayment(double amount){
         if(amount >= total){
            this->payed = true;
        } else {
            cerr<<"Insufficient amount. Please pay the full amount to proceed."<<endl;
        }
        this->payed = payed;
    }
};

int Order::nextOrderId = 0;

#endif