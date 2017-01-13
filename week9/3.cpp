#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/* facade pattern*/
//step 1: create an interface
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
        cout << "Rectangle::draw()" << endl;
    }
};

class Square : public Shape
{
  public:
    void draw()
    {
        cout << "Square::draw()" << endl;
    }
};

class Circle : public Shape
{
  public:
    void draw()
    {
        cout << "Circle::draw()" << endl;
    }
};

//step 3: Create a facade class
class ShapeMaker
{ 
  private:
    Shape *circle = new Circle;
    Shape *rectangle = new Rectangle;
    Shape *square = new Square;

  public:
    void drawCircle()
    {
        circle->draw();
    }

    void drawRectangle()
    {
        rectangle->draw();
    }

    void drawSquare()
    {
        square->draw();
    }
};

int main()
{
    ShapeMaker *shapeMaker = new ShapeMaker;
    shapeMaker->drawCircle();
    shapeMaker->drawRectangle();
    shapeMaker->drawSquare();
    return 0;
}