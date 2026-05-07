#include <bits/stdc++.h>
using namespace std;

//Real Life car

/*
Abstract class --> 
Abstraction hide unnecessary details from the client , and showcase only what is necessary

1. Act as an interface for the outside world to operate the car. 
2. This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that.
3. Since this is an abstract class we cannot directly create Objects of this class. 
4. We need to Inherit it first and then that child class will have the responsibility to 
provide implementation details of all the abstract (virtual) methods in the class.

5. In our real world example of Car, imagine you sitting in the car and able to operate
the car (startEngine, accelerate, brake, turn) just by pressing or moving some
pedals/buttons/ steer the wheel etc. You dont need to know how these things work, and
also they are hidden under the hood.
6. This Class 'Car' denotes that (pedals/buttons/steering wheel etc). 
*/


class Car{
    public:
        // virtual tell we are only declaring not defing it's child class responsiblity to define it 
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};


/*
1. This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

2. In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or steering wheel). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

3. Therefore, to denote a real world car in programming we created 2 classes.
One to denote all the user-interface like pedals, buttons, steering wheels etc ('Car' class).And,
Another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
 
*/

class SportsCar : public Car {
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m) {
        // What you have is valid. this-> is only required when a parameter/local has the same name as a member (e.g. brand and brand); here parameters are b and m, so brand = b; and model = m; would be equivalent.
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; //neutral
    }

    void startEngine() {
        isEngineOn = true;
        cout<<"Engine started of your Sports Car"<<endl;
    }

    void shiftGear(int gear) {
        if(!isEngineOn){
            cout<<brand<<" : "<<model<<" : "<<"Please start The engine first"<<endl;
            return ;
        }
        currentGear = gear;
        cout<<brand<<" : "<<model<<" : "<<"shifted to gear "<<currentGear<<endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main(){
    /*
    You are creating a SportsCar object on the heap using new.
    Storing it in a pointer of type Car* (base class pointer).
    This enables polymorphism.

        ✔ Runtime polymorphism works (virtual functions)
        ✔ Useful for dynamic behavior
        ❗ You must manually delete it to avoid memory leaks
    */
    Car *myCar = new SportsCar("Ford", "Mustang");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();


    delete myCar;

    /*
    You are using a unique_ptr to manage the memory of the SportsCar object.
    This is a smart pointer that automatically deletes the object when it goes out of scope.
    */


    unique_ptr<Car> myCar2 = make_unique<SportsCar>("Ford", "Mustang");
    myCar2->startEngine();
    myCar2->shiftGear(1);
    myCar2->accelerate();
    myCar2->shiftGear(2);
    myCar2->accelerate();
    myCar2->brake();
    myCar2->stopEngine();

    /*
    You are creating a SportsCar object on the stack.
    Storing it in a variable of type SportsCar (concrete class).
    This does not enable polymorphism.

        ✔ Compile-time polymorphism works (overloading)
        ✔ Useful for static behavior
        ❗ You don't need to manually delete it
    */
    // SportsCar mySportsCar("Ford", "Mustang");
    // mySportsCar.startEngine();
    // mySportsCar.shiftGear(1);
    // mySportsCar.accelerate();
    // mySportsCar.shiftGear(2);
    // mySportsCar.accelerate();
    // mySportsCar.brake();
    // mySportsCar.stopEngine();

    // delete myCar;    

    return 0;
}
