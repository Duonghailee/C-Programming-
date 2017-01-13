#include <iostream>
#include <string>
#include <stdlib.h> //srand, rand
#include <time.h>   //time seed
#include <map>      //std::insert, std::find
using namespace std;

/* Decorate pattern */
// step 1: create an interface
class Shape
{
  public:
    virtual void draw() = 0;
};

//step 2: Create concrete classes implementing the same interface.
class Rectangle : public Shape
{
  public:
    void draw()
    {
        cout << "Shape: Rectangle" << endl;
    }
};

class Circle : public Shape
{
  public:
    void draw()
    {
        cout << "Shape: Circle" << endl;
    }
};

//step 3: Create abstract decorator class implementing the Shape interface.
class ShapeDecorator : public Shape
{
  protected:
    Shape *decoratedShape;

  public:
    ShapeDecorator(Shape *new_decoratedShape)
    {
        decoratedShape = new_decoratedShape;
    }

    void draw()
    {
        decoratedShape->draw();
    }
};

//step 4: Create concrete decorator class extending the ShapeDecorator class.

class RedShapeDecorator : public ShapeDecorator
{
  public:
    RedShapeDecorator(Shape *new_decoratedShape) : ShapeDecorator(new_decoratedShape)
    {
    }

    void setRedBorder(Shape *decoratedShape)
    {
        cout << "Border Color: Red" << endl;
    }
    void draw()
    {
        ShapeDecorator::draw();
        setRedBorder(ShapeDecorator::decoratedShape);
    }
};

//step 3: verify results
int main()
{
    Shape *circle = new Circle();

    Shape *redCircle = new RedShapeDecorator(new Circle());

    Shape *redRectangle = new RedShapeDecorator(new Rectangle());
    cout << "Circle with normal border" << endl;
    circle->draw();

    cout << "\nCircle of red border" << endl;
    redCircle->draw();

    cout << "\nRectangle of red border" << endl;
    redRectangle->draw();
    return 0;
}
