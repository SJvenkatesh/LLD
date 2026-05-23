#include<bits/stdc++.h>

using namespace std;

class Product{
	public:
	string name;
	double price;
	
	Product(string name, double price) {
		this->name = name;
		this->price = price;
	}
};

class ShoppingCart {
	private:
	vector<Product*> products;
	public:
	
	void addProduct(Product *p){
		products.push_back(p);
	}
	
	const vector<Product*> getProduct() {
		return products;
	} 
	
	double calculateTotal(){
        	double total = 0.0;
		for(auto p : products) {
            cout<<"Product: "<<p->name<<", Price: "<<p->price<<endl;
            total += p->price;
        }
        return total;
	}
};

class InvoicePrinter {
    private:
	class ShoppingCart *sc;
    public:
    InvoicePrinter(ShoppingCart *shoppingCart) {
    	this->sc = shoppingCart;
    }
    
      void printInvoice() {
        cout<<"Invoice Details:"<<endl;
        for(auto p : sc->getProduct()) {
            cout<<"Product: "<<p->name<<", Price: "<<p->price<<endl;
        }
        cout<<"Total Amount: "<<sc->calculateTotal()<<endl;
    }
    
};	

int main() {
    
	class ShoppingCart *sc = new ShoppingCart();	
	sc->addProduct(new Product("car",400));
	sc->addProduct(new Product("car1",100));
	class InvoicePrinter *ip = new InvoicePrinter(sc);
	ip->printInvoice();
}