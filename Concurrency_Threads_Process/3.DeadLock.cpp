#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m1, m2;

void threadA() {
    cout << "Thread A trying to acquire m1" << endl;
    m1.lock();
        cout << "Thread A acquired m1" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    m2.lock();
    cout << "Thread A acquired m2" << endl;
    // critical section
    m2.unlock();
    m1.unlock();
    cout << "Thread A released m1 and m2" << endl;
}

void threadB() {
    cout << "Thread B trying to acquire m2" << endl;
    // m2.lock(); // This will cause deadlock as thread A is holding m1 and waiting for m2, while thread B is holding m2 and waiting for m1
    m1.lock();
    cout << "Thread B acquired m2" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // m1.lock(); // This will cause deadlock as thread A is holding m1 and waiting for m2, while thread B is holding m2 and waiting for m1
    m2.lock();
    cout << "Thread B acquired m1" << endl;
    // critical section
    // m1.unlock();
    // m2.unlock();
    m2.unlock();
    m1.unlock();
    cout << "Thread B released m1 and m2" << endl;
}

int main() {
    cout << "Main thread started!" << endl;
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();
    cout<< "Threads completed!" << endl;
    return 0;
}