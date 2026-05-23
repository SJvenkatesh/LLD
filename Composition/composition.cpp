#include<bits/stdc++.h>

using namespace std;

class Car {
    public:
    string brand;
    string model;
    public:
    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
    virtual bool startEngine() {
        cout<<"Engine started of your Car"<<endl;
        return true;
    }
     virtual ~Car() {} // Virtual destructor for proper cleanup of derived classes.
};

class ManualCar : public Car {
    public:
    int enginePower;
    int currentGear;
    ManualCar(string b, string m) {
        this->brand = b;
        this->model = m;
        currentGear = 0;
        enginePower = 150; // Example engine power
    }
    bool startEngine() {
        cout<<"Engine started of your Manual Car"<<endl;
        return true;
    }
};


class Electric : public Car {
	private:
     int enginePower;
    public:
    Electric(string b, string m) {
        this->brand = b;
        this->model = m;
        this->enginePower = 150; // Example engine power
    }
    bool startEngine() {
        cout<<"Engine started of your Electric Car"<<endl;
        return true;
    }
};

class LuxManualCar : public Car {
	private:
	int price;
    Car *manualCar; // Composition: LuxManualCar has a ManualCar
	public:
	LuxManualCar(int price) {
		this->manualCar = new ManualCar("BMW", "X7");	
		this->manualCar->startEngine();
		this->price = price;
	}
    void displayDetails() {
        cout << "Brand: " << this->manualCar->brand << ", Model: " << this->manualCar->model << ", Price: $" << this->price << endl;
    }
};

int main() {
    Car* myCar = new LuxManualCar(100000);
    myCar->displayDetails();
    return 0;

}

