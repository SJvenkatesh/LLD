#ifndef TOMATOAPP_H
#define TOMATOAPP_H


#include "models/Restaurant.h"
#include "models/MenuItem.h"
#include "models/User.h"
#include "models/Cart.h"
#include "models/Order.h"
#include "models/DeliveryOrder.h"
#include "models/PickupOrder.h"
#include "Factory/OrderFactory.h"
#include "Factory/InstanceOrder.h"
#include "Factory/ScheduledOrder.h"
#include "Manager/RestaurantManager.h"
#include "Manager/OrderManager.h"
#include "Utils/TimeUtils.h"
#include "Strategy/PaymentStrategy.h"
#include "Strategy/CardPayment.h"
#include "Strategy/UpiPayment.h"

class TomatoApp {
      
      public:
    TomatoApp() {
    	initializeRestaurant();
    }
    
    void initializeRestaurant() {
		cout<<"Initializing restaurants and menus"<<endl;
    	Restaurant *restaurant1 = new Restaurant("Restaurant1", "location1");
    	MenuItem *menu1 = new MenuItem("menu1", 100, "100 calories");
    	MenuItem *menu2 = new MenuItem("menu2", 200, "200 calories");
    	MenuItem *menu3 = new MenuItem("menu3", 300, "300 calories");
    	restaurant1->addMenuItem(*menu1);
    	restaurant1->addMenuItem(*menu2);
    	restaurant1->addMenuItem(*menu3);
    	
    	Restaurant *restaurant2 = new Restaurant("Restaurant2", "location2");
    	MenuItem *menu4 = new MenuItem("menu4", 100, "100 calories");
    	MenuItem *menu5 = new MenuItem("menu5", 200, "200 calories");
    	MenuItem *menu6 = new MenuItem("menu6", 300, "300 calories");
    	
    	restaurant2->addMenuItem(*menu4);
    	restaurant2->addMenuItem(*menu5);
    	restaurant2->addMenuItem(*menu6);
    	
    	
    	RestaurantManager *rm = RestaurantManager::getInstance();
    	rm->addRestaurant(*restaurant1);
    	rm->addRestaurant(*restaurant2);

		User *user = new User(1, "John", "123 Main St");
		Cart *cart = new Cart();
		cart->setRestaurant(restaurant1);
		cart->addItem(*menu1);
		cart->addItem(*menu2);
		cart->addItem(*menu3);
		cout<<"Total cost of cart: "<<cart->getTotalCost()<<endl;
		PaymentStrategy *ps = new CardPayment("1234567890");
		OrderManager *om = OrderManager::getInstance();
		om->addOrder(new DeliveryOrder());
		om->addOrder(new PickupOrder());
		om->listOrders();
    }
};

#endif
