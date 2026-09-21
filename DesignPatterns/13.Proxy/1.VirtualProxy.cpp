#include<bits/stdc++.h>

using namespace std;

class IImage {
    public:
    virtual void display() = 0;
};

class RealImage : public IImage {
    string fileName;
    public:
    RealImage(string name) {
        this->fileName = name;
    }
    void display() override {
        cout<<"[RealImage] Output : "<<this->fileName<<endl;
    }
};

class ProxyImage : public IImage {
    IImage *im;
    string fileName;
    public:
    ProxyImage(string name){
        im=NULL;
        this->fileName = name;
    }
    void display() override {
        if(im==NULL){
            im=new RealImage(fileName);
        } 
        im->display();
    }
};

int main () {
    IImage *im = new ProxyImage("sample.jpg");
    im->display();
    return 0;
}