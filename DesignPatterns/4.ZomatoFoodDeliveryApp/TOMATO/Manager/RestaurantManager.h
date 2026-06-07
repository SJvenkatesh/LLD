#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <bits/stdc++.h>
#include "../models/Restaurant.h"

using namespace std;

class RestaurantManager{
	private:
	vector<Restaurant> restaurant;
	static RestaurantManager *instance;
	
	RestaurantManager(){
		//making it private constructer
	};
	
	public:
	
    static RestaurantManager *getInstance() {
        if(!instance){
            instance = new RestaurantManager();
        }
        return instance;
    }

	void addRestaurant(Restaurant &res){
		restaurant.push_back(res);
	}
	
	const vector<Restaurant> getRestaurants() {
		return restaurant;
	}
	
	vector<Restaurant> searchByLocation(const string &location) {
		vector<Restaurant> res;
		for (const auto &r : restaurant) {
			if (r.getLocation() == location) {
				res.push_back(r);
			}
		}
		return res;
	}
	
};

RestaurantManager* RestaurantManager::instance = NULL;

#endif