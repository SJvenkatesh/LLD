#include <bits/stdc++.h>

using namespace std;

class ICommand {
    public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Light {
    public:
    void on() {
        cout<<"Light On"<<endl;
    }
    void off() {
        cout<<"Light off"<<endl;
    }
};

class Fan {
    public:
        void on() {
            cout<<"Fan On"<<endl;
        }
        void off() {
            cout<<"Fan off"<<endl;
        }
};

class LightCommand : public ICommand {
    class Light *lg;
    public:
    LightCommand(Light *light){
        this->lg = light;
    }
    void execute() {
        lg->on();
    }
    void undo() {
        lg->off();
    }
};


class FanCommand : public ICommand {
    class Fan *fan;
    public:
    FanCommand(Fan *fa){
        this->fan = fa;
    }
    void execute() {
        fan->on();
    }
    void undo() {
        fan->off();
    }
};

class RemoteController{
    static const int maxKey = 2;
    ICommand *command[maxKey];
    bool button[maxKey];
    public:
    RemoteController() {
        command[0] = new LightCommand(new Light());
        button[0] = false;
        command[1] = new FanCommand(new Fan());
        button[1] = false;
    }

    void pressButton(int key){
        if(key>=maxKey){
            cerr<<"Invalide key"<<endl;
        }
        if(button[key]){
            command[key]->undo();
            button[key]=false;
        } else {
            command[key]->execute();
            button[key]=true;
        }
    }
};

int main() {
    class RemoteController *rc1 = new RemoteController();
    rc1->pressButton(0);
    rc1->pressButton(0);
    rc1->pressButton(0);
    rc1->pressButton(1);
    rc1->pressButton(1);
    return 0;
}