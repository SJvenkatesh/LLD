#ifndef MENUITEM_H
#define MENUITEM_H

#include<bits/stdc++.h>

using namespace std;

class MenuItem {
private:
    string name;
    double price;
	string code;
public:
	MenuItem(const string &name, const double &price, const string &code) {
		this->name = name;
		this->price = price;
		this->code = code;
	}
    // Getters and setters
	string getName() const {
		return name;
	}
	
	void setName(const string &name){
		this->name = name;
	}
	
	double getPrice() const {
		return price;
	}
	
    void setPrice(const double price){
        this->price = price;
    }

    string getCode() const {
        return code;
    }

    void setCode(const string &code) {
        this->code = code;
    }

	~MenuItem(){
		cout<<"Destructing MenuItem class "<<this->name<<endl;
	}
};

#endif