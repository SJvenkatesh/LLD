#include<bits/stdc++.h>

using namespace std;

class Burger {
	public:
	virtual void prepare() = 0;
	virtual ~Burger(){}
};

class BasicBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Basic burger"<<endl;
	}
};

class StandardBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Standard burger"<<endl;
	}
};

class PremiumBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Premium burger"<<endl;
	}
};

class BurgerFactory {
	public:
	Burger* createBurger(string type) {
		if(type == "Basic") {
			return new BasicBurger();
		} else if(type == "Standard") {
			return new StandardBurger();
		} else if(type == "Premium") {
			return new PremiumBurger();
		} else {
			cout<<"Invalid Burger type";
			return NULL;
		}
	}

};

int main() {
	
	string type = "Premium";
	class BurgerFactory *bf = new BurgerFactory();
	class Burger *b= bf->createBurger(type);
	b->prepare();
	return 0;
}