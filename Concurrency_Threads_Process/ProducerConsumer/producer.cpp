#include <iostream>
#include "shared.h"
#include "bits/stdc++.h"
#include "thread_functions.h"

using namespace std;

void producer() {
    for (int i = 1; i <= 5; i++) {

        {
            cout << "Producer trying to acquire lock to produce " << i << endl;
            unique_lock<mutex> lock(mtx);

            q.push(i);

            cout << "Produced: " << i << endl;
        }

        cv.notify_one();
        // this_thread::sleep_for(chrono::milliseconds(100)); // Simulate time taken to produce an item for producer and conumer to consume it for every event producer produced .
    }
}