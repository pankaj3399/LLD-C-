#include <iostream>
#include <string>

using namespace std;

class ShapeInterface
{
public:
    virtual void draw() = 0;
};

class Circle : public ShapeInterface
{
public:
    void draw()
    {
        cout << "Circle" << endl;
    }
};

class Rectangle : public ShapeInterface
{
public:
    void draw()
    {
        cout << "Rectangle" << endl;
    }
};

class Square : public ShapeInterface
{
public:
    void draw()
    {
        cout << "Square" << endl;
    }
};

class ShapeFactory
{
public:
    ShapeInterface *getShape(string name)
    {
        if (name == "Circle")
            return new Circle();
        else if (name == "Rectangle")
            return new Rectangle();
        else
            return new Square();
    }
};

int main()
{
    ShapeFactory *factory = new ShapeFactory();
    factory->getShape("Circle")->draw();
    return 0;
}