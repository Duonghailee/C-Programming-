#include <iostream> // std:cout
using namespace std;

//step 1,interface
class Shape
{
  public:
    virtual void draw() = 0;
};

// step 2: 3 concret classes
class Square : public Shape
{
  public:
    void draw()
    {
        cout << "Inside Square::draw() method." << endl;
    }
};

class Rectangle : public Shape
{
  public:
    void draw()
    {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};

class Circle : public Shape
{
  public:
    void draw()
    {
        cout << "Inside Circle::draw() method." << endl;
    }
};

//step 3: Factory to generate object of concrete class MyClass
class ShapeFactory
{
  public:
    Shape *getShape(const char *shapeType)
    {
        if (strcmp(shapeType, "RECTANGLE") == 0)
        {
            return new Rectangle;
        }
        else if (strcmp(shapeType, "SQUARE") == 0)
        {
            return new Square;
        }
        else if (strcmp(shapeType, "CIRCLE") == 0)
        {
            return new Circle; 
        }
        else
        {
            return NULL; // the reason I use pointer is that object can not be assigned NULL , only pointer to that object can be.
        }
    }
};

int main()
{

    ShapeFactory factory;
    Shape *cir = factory.getShape("CIRCLE");
    cir->draw();

    Shape *rect = factory.getShape("RECTANGLE");
    rect->draw();

    Shape *square = factory.getShape("SQUARE");
    square->draw();

    return 0;
}
