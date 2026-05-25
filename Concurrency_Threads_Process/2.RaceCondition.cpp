#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int counter = 0;
mutex mtx;

void increment() {
    for(int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(mtx); // locks automatically
        counter++;
    }// lock destroyed here, mutex unlocked
}
int counter1 = 0;
mutex mtx1;
void increment1() {
    for(int i = 0; i < 100000; i++) {
        unique_lock<mutex> lock(mtx1); // locks automatically
        counter++;
        // lock.unlock(); // unlocks 
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

   cout << "Counter: " << counter <<endl; // Counter: 200000
   
    thread t3(increment1);
    thread t4(increment1);

    t3.join();
    t4.join();

    cout << "Counter1: " << counter <<endl; // Counter1: 400000
}