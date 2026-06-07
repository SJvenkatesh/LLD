#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Restaurant {
    private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<class MenuItem> menu; 
    public:

    Restaurant(const string &name, const string &location) {
        this->restaurantId = ++nextRestaurantId;
        this->name = name;
        this->location = location;
    }

    string getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    string getLocation() const {
        return location;
    }

    void setLocation(const string &location) {
        this->location = location;
    }

    const vector<MenuItem> getMenu() const {
        return menu;
    }

    void addMenuItem(const MenuItem &menuItem) {
        menu.push_back(menuItem);
    }

    ~Restaurant(){
    	cout<<"Destorying Restaurant"<<name<<", and clearing it's menu"<<endl;
    	menu.clear();
    }
};

int Restaurant::nextRestaurantId = 0;

#endif