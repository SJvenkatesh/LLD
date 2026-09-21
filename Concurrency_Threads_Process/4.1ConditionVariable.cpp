#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;

bool ready = false;

void consumer()
{
    cout << "Consumer started\n";

    unique_lock<mutex> lock(mtx);

    cout << "Consumer waiting...\n";

    cv.wait(lock, [] {
        return ready;
    });

    cout << "Consumer resumed!\n";
}

void producer()
{
    this_thread::sleep_for(chrono::seconds(3));

    unique_lock<mutex> lock(mtx);

    cout << "Producer setting ready = true\n";

    ready = true;

    lock.unlock();

    // cout << "Producer notifying...\n";
    // cv.notify_one();

    cout << "Producer notifying commented...\n";
}

int main()
{
    thread t1(consumer);
    thread t2(producer);

    t1.join();
    t2.join();
}

// output without notify comment

// Consumer started
// Consumer waiting...
// Producer setting ready = true
// Producer notifying...
// Consumer resumed!

// output with notify commented

// Consumer started
// Consumer waiting...
// Producer setting ready = true
// Producer notifying commented...
