// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>
// #include <queue>
#include<bits/stdc++.h>
using namespace std;
std::mutex mtx;
std::condition_variable cv;
std::queue<int> q;

void producer() {
    for (int i = 1; i <= 5; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one(); // Notify one waiting consumer
        cout << "Producer notified consumer after producing " << i << std::endl;
    }
}

void consumer() {
    while (true) {
        cout << "Consumer waiting for items..." << endl;
        std::unique_lock<std::mutex> lock(mtx);
        cout<< "Consumer waiting for items after unique_lock" << endl;
        cv.wait(lock, [] { return !q.empty(); }); // Wait until queue is not empty
        cout<< "Consumer notified and woke up" << endl;
        int value = q.front();
        q.pop();
        std::cout << "Consumed: " << value << std::endl;
        if (value == 5) break; // Exit after last item
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}