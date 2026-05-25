#include <iostream>
#include "shared.h"
#include "thread_functions.h"

using namespace std;

void consumer() {

    while (true) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return !q.empty();
        }); // "Hey consumer, you may continue when scheduler allows and mutex becomes available."

        int value = q.front();
        q.pop();

        cout << "Consumed: " << value << endl;

        if (value == 5)
            break;
    }
}