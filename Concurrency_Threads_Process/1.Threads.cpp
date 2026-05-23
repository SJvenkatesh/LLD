#include<bits/stdc++.h>
#include <thread>
using namespace std;


void hello() {
    cout << "Hello from thread!"<< this_thread::get_id() << endl;
    //some io operation happing here
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread work done!" << this_thread::get_id() << endl;
}

int main() {
    cout << "Main thread started!"<<this_thread::get_id()<<endl;

    int n = thread::hardware_concurrency(); // Get the number of concurrent threads supported by the hardware
    cout << "Number of concurrent threads supported: " << n << endl;

    //Number of threads to create 


    thread t1(hello);
    thread t2(hello);
    thread t3(hello);

    t1.join();
    t2.join();
    t3.join();

    cout << "All threads completed!" << endl;
    return 0;
}