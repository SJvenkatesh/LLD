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

class BasicWheatBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Basic Wheat burger"<<endl;
	}
};

class StandardWheatBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Standard Wheat burger"<<endl;
	}
};

class PremiumWheatBurger : public Burger {
	public:
	void prepare() override {
		cout<<"Preparing Premium Wheat burger"<<endl;
	}
};

class BurgerFactory {
	public:
	virtual Burger* createBurger(string type) = 0; 
};

class singhBurger: public BurgerFactory {
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

class kingBurger: public BurgerFactory {
	public:
	Burger* createBurger(string type) {
		if(type == "Basic") {
			return new BasicWheatBurger();
		} else if(type == "Standard") {
			return new StandardWheatBurger();
		} else if(type == "Premium") {
			return new PremiumWheatBurger();
		} else {
			cout<<"Invalid Burger type";
			return NULL;
		}
	}
};


int main() {
	
	string type = "Premium";
	class BurgerFactory *bf = new singhBurger();
	class Burger *b= bf->createBurger(type);
	b->prepare();

    class BurgerFactory *kbf = new kingBurger();
	class Burger *kb= kbf->createBurger(type);
	kb->prepare();
	return 0;
}