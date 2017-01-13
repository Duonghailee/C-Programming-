#include <iostream>
using namespace std;

class Shape
{
    // instance variables
  protected:
    int width;
    int height;

    // set value method
  public:
    void set_values(int w, int h)
    {
        width = w;
        height = h;
    }
};

// subclass that inherit the class Shape
class Rectangle : public Shape
{
  public:
    int area()
    {
        return width * height;
    }
};

// subclass
class Triangle : public Shape
{
  public:
    int area()
    {
        return 0.5 * width * height;
    }
};

int main()
{
    Rectangle Rect;
    Triangle Tria;
    Rect.set_values(5,3);
    Tria.set_values(2,5);
    cout << (Rect.area()) << endl;
    cout << (Tria.area()) << endl;
    return 0;
}
