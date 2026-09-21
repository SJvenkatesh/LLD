#include<bits/stdc++.h>
using namespace std;

class UnisexBathroom {
    mutex mtx;
    condition_variable cv;
    int counter;

    public:
        UnisexBathroom() {
            this->counter = 0; // Positive for netural
        }

    void maleUseBathroom(string name) {
        unique_lock<mutex> l(mtx);
        cv.wait(l, [this] { return counter >=0 && counter <3; }); // Wait until bathroom is empty or occupied
        counter++;
        cout<<"Male ("<<name<<") entered bathroom. Current count: "<<counter<<endl;
        l.unlock();
        this_thread::sleep_for(chrono::seconds(1)); // Simulate time taken in bathroom
        cout<<"Male ("<<name<<") leaving bathroom. Current count: "<<counter<<endl;
        l.lock();
        counter--;
        l.unlock();
        cv.notify_all();
    }
    void femalUseBathroom(string name) {
        unique_lock<mutex> l(mtx);
        cv.wait(l, [this] { return counter <=0 && counter >-3; }); // Wait until bathroom is empty or occupied
        counter--;
        cout<<"Female ("<<name<<") entered bathroom. Current count: "<<counter<<endl;
        l.unlock();
        this_thread::sleep_for(chrono::seconds(1)); // Simulate time taken in bathroom
        cout<<"Female ("<<name<<") leaving bathroom. Current count: "<<counter<<endl;
        l.lock();
        counter++;
        l.unlock();
        cv.notify_all();
    }
};

void maleThread(UnisexBathroom *bathroom, string name) {
    bathroom->maleUseBathroom(name); // Simulate time taken in bathroom
}

void femaleThread(UnisexBathroom *bathroom, string name) {
    bathroom->femalUseBathroom(name);
}


int main() {
    class UnisexBathroom *bathroom = new UnisexBathroom();

    thread t1(maleThread, bathroom, "John");
    thread t2(femaleThread, bathroom, "Riya");
    thread t3(maleThread, bathroom, "Mike");
    thread t4(maleThread, bathroom, "David");
    thread t5(femaleThread, bathroom, "Sara");
    thread t6(femaleThread, bathroom, "Emily");


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}