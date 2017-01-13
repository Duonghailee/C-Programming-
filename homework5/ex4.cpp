
#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
  protected:
    float width, height;

  public:
    void set_data(float a, float b)
    {
        width = a;
        height = b;
    }
    virtual float area() = 0;
};

class Rectangle : public Shape
{
  public:
    float area()
    {
        return (width * height);
    }
};

class Triangle : public Shape
{
  public:
    float area()
    {
        return (width * height / 2);
    }
};

class Eclipse : public Shape
{
  public:
    float area()
    {
        return M_PI * width * height;
    }
};

class Square : public Rectangle
{
  public:
    void set_data(float a)
    {
        width = a;
        height = a;
    }
};

class Circle : public Eclipse
{
  public:
    void set_data(float r)
    {
        width = r;
        height = r;
    }
};

int main()
{

    Rectangle rect;
    Triangle tri;
    Eclipse eclip;
    Square square;
    Circle cir;

    rect.set_data(5, 3);
    tri.set_data(2, 5);
    eclip.set_data(4, 6);
    square.set_data(4);
    cir.set_data(1);

    cout << "Area of rectanlge = " << rect.area() << endl;
    cout << "Area of trianlge = " << tri.area() << endl;
    cout << "Area of eclipse = " << eclip.area() << endl;
    cout << "Area of square = " << square.area() << endl;
    cout << "Area of circle = " << cir.area() << endl;
    return 0;
}