#ifndef CART_H
#define CART_H

#include <bits/stdc++.h>
#include "Restaurant.h"
#include "MenuItem.h"

using namespace std;

class Cart {
	private:
	Restaurant *restaurant;
	vector<MenuItem> items;
	public:
	
	Cart() {
		restaurant = NULL;
	}
	
	void addItem(const MenuItem &item) {
		if(!restaurant){
			cerr<<"Cart: Set a restaurant before adding items."<<endl;
			return;
		}
		items.push_back(item);
	}
	
	double getTotalCost(){
		double totalSum = 0;
		for(auto it : items){
			totalSum = totalSum + it.getPrice();
		}
		return totalSum;
	} 
	
	bool isEmpty() {
		return !restaurant || items.empty();
	}
	
	const vector<MenuItem> getItems() const {
		return items;
	}
	
	void clear() {
		items.clear();
		restaurant = NULL;
	}
	
	Restaurant* getRestaurant() const{
		return restaurant;
	}
	
    void setRestaurant(Restaurant *restaurant) {
        if (this->restaurant && this->restaurant != restaurant) {
            cerr << "Cart: Cannot change restaurant. Clear the cart first." << endl;
            return;
        }
        this->restaurant = restaurant;
    }

	~Cart() {
		cout<<"Destroying Cart and clearing items"<<endl;
		items.clear();
	}
};

#endif