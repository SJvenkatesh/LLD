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
            // cout<<"Product: "<<p->name<<", Price: "<<p->price<<endl;
            total += p->price;
        }
        return total;
	}

    void printInvoice() {
        cout<<"Invoice Details:"<<endl;
        for(auto p : products) {
            cout<<"Product: "<<p->name<<", Price: "<<p->price<<endl;
        }
        cout<<"Total Amount: "<<calculateTotal()<<endl;
    }

    void saveToDatabase() {
        cout<<"Saving invoice to database..."<<endl;
        // Simulate database save operation
    }
};


int main() {

	ShoppingCart *sc = new ShoppingCart();
	
	sc->addProduct(new Product("car",100));
    sc->addProduct(new Product("car1",100));

	sc->printInvoice();
    delete sc;
}