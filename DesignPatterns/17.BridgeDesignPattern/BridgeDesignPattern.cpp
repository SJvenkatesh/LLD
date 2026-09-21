#include <bits/stdc++.h>

using namespace std;

class Engine {
    public:
        virtual void start() = 0;
        virtual ~Engine(){}
};

class PetrolEngine : public Engine {
    public:
        void start() override{
        cout << "Petrol engine starting with ignition!" << endl;
        }
};

class DieselEngine : public Engine {
public:
    void start() override {
        cout << "Diesel engine roaring to life!" << endl;
    }
};

class ElectricEngine : public Engine {
public:
    void start() override {
        cout << "Electric engine powering up silently!" << endl;
    }
};

class Car {
    protected:
        Engine *engine;
    public:
        Car(Engine *engine){
            this->engine = engine;
        }
        virtual void drive() = 0;
};

class Sedan : public Car {
    public:
    Sedan(Engine *engine)
        :Car(engine){}
    void drive() override {
        engine->start();
        cout << "Driving a Sedan on the highway." << endl;
    }
};

// Refined Abstraction: SUV
class SUV : public Car {
public:
    SUV(Engine* e) : Car(e) {}

    void drive() override {
        engine->start();
        cout << "Driving an SUV off-road." << endl;
    }
};

int main() {
    // Create Engine implementations on the heap
    Engine* petrolEng = new PetrolEngine();
    Engine* dieselEng = new DieselEngine();
    Engine* electricEng = new ElectricEngine();

    // Create Car abstractions, injecting Engine implementations
    Car* mySedan = new Sedan(petrolEng);
    Car* mySUV = new SUV(electricEng);
    Car* yourSUV = new SUV(dieselEng); // electric

    // Use the cars
    mySedan->drive();   // Petrol engine + Sedan
    mySUV->drive();     // Electric engine + SUV
    yourSUV->drive();   // Diesel engine + SUV

    // Clean up
    // delete mySedan;
    // delete mySUV;
    // delete yourSUV;

    return 0;
}
