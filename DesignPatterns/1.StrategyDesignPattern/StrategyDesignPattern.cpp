#include<bits/stdc++.h>

using namespace std;

// --- Strategy Interface for Walk ---
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// --- Concrete Strategies for walk ---
class NormalWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Walking normally..." << endl; 
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Cannot walk." << endl; 
    }
};


class TalkableRobot {
public:
	virtual void talk() = 0;
	virtual ~TalkableRobot() {}

};

class NormalTalk : public TalkableRobot {
public:
	void talk() override {
		   cout << "Talking normally..." << endl; 
	}

};

class NoTalk : public TalkableRobot {
public:
	void talk() override {
		  cout << "Cannot talk." << endl;  
	}

};

// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

class Robot {
	protected:
	class WalkableRobot *wr;
	class TalkableRobot *tr;
	class FlyableRobot *fr;
	
	public: 
	Robot(class WalkableRobot *wr, class TalkableRobot *tr, class FlyableRobot *fr) {
	 	this->wr = wr;
	 	this->tr = tr;
	 	this->fr = fr;
	 }
	void walk() { 
        wr->walk(); 
    }
    void talk() { 
        tr->talk(); 
    }
    void fly() { 
        fr->fly(); 
    }
	 virtual void projection() = 0;
};

// --- Concrete Robot Types ---
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main(){

	class WalkableRobot* normalwr = new NormalWalk();
	class WalkableRobot* nowr = new NoWalk();
	
	class TalkableRobot* normaltr = new NormalTalk();
	class TalkableRobot* notr = new NoTalk();	
	
	class FlyableRobot* normalfr = new NormalFly();
	class FlyableRobot* nofr = new NoFly();	

	class Robot *r = new CompanionRobot(normalwr, notr, normalfr);
	
	r->walk();
	r->talk();
	r->fly();
	r->projection();


    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
	
	return 0;
}