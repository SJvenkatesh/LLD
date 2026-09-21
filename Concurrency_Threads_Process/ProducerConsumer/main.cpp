#include <thread>
#include "thread_functions.h"

using namespace std;

int main() {

    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}