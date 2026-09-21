#ifndef SHARED_H
#define SHARED_H

#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

extern queue<int> q;
extern mutex mtx;
extern condition_variable cv;

#endif