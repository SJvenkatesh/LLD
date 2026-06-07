#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
#include "Cart.h"
using namespace std;

class User {
	private:
	string name;
	int userId;
    string address;
	class Cart *cart;
	public:
	User(const int userId, const string name, const string address) {
		this->name = name;
        this->address = address;
		this->userId = userId;
		cart = new Cart();
	}
	//getters and setters
    string getName() const {
        return name;
    }
    
    void setName(const string &name) {
        this->name = name;
    }

    int getUserId() const {
        return userId;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        this->address = address;
    }

    Cart* getCart() const {
        return cart;
    }

    ~User(){
    	cout<<"Destroying User "<<name<<endl;
    	delete cart;
    }
};

#endif