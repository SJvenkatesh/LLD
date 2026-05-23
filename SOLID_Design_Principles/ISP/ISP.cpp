#include <iostream>
#include <stdexcept>

using namespace std;


class TwoDimentionShape {
public:
    virtual double area() = 0;
};

class ThreeDimentionShape {
public:
    virtual double area() = 0;
    virtual double volume() = 0; 
};

class Square : public TwoDimentionShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
};

class Rectangle : public TwoDimentionShape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

};

// Cube is a 3D shape, so it actually has a volume
class Cube : public ThreeDimentionShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main() {
    TwoDimentionShape* square = new Square(5);
    TwoDimentionShape* rectangle = new Rectangle(4, 6);
    ThreeDimentionShape* cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;
    
    return 0;
}