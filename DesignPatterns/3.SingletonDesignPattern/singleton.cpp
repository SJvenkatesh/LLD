#include<bits/stdc++.h>
using namespace std;

//Real World Example
// Logging System
// Database Connection
// Configuration Manager


class Singleton {
	private:
	static Singleton* instance;
	static mutex mtx;
	Singleton(){
		cout<<"Singleton Constructor called. New Object Created."<<endl;
	}
	public:
	static Singleton* getInstance() {
		// lock_gaurd<mutex> lock(mtx); // Every time we call getInstance, it will lock the mutex, which can lead to performance issues.
		if(instance == NULL){
			lock_guard<mutex> lock(mtx); // Lock the mutex only when instance is NULL, which reduces the performance overhead.
			if(instance == NULL){
				return instance = new Singleton();
			} // Double-checked locking to ensure that only one instance is created even in a multithreaded environment.
		}
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
	class Singleton *s1 = Singleton::getInstance();
	class Singleton *s2 = Singleton::getInstance();
	
	if(s1==s2){
		cout<<"Both are same"<<endl;
	}
	return 0;
}