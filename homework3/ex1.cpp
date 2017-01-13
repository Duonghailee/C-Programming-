#include <iostream>
using namespace std;

class Figure
{
    // instance variables
  protected:
    int x;
    int y;

    // set value method
  public:
    void set_X(int x_value)
    {
        x = x_value;
    }
    void set_Y(int y_value)
    {
        y = y_value;
    }

    int get_X()
    {
        return x;
    }

    int get_Y()
    {
        return y;
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

// subclass that inherit the class Figure
class Point : public Figure
{
  public:
    void show()
    {
        cout << "I am figure (" << get_X() << ", " << get_Y() << ")" << endl;
    }
};

// subclass
class Circle : public Figure
{
  protected:
    int radius;

  public:
    void set_radius(int r)
    {
        radius = r;
    }
    void show()
    {
        cout << "I'm circle which radius is " << radius << " and mid point is (" << get_X() << "," << get_Y() << ")" << endl;
    }
};
// ex2. Rectangle class
class Rectangle : public Point
{
  private:
    int width;
    int height;

  public:
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    void set_width(int w)
    {
        width = w;
    }
    void set_height(int h)
    {
        height = h;
    }
    int area()
    {
        return width * height;
    }
};

// ex3. class ScreenRectangle
class ScreenRectangle : public Rectangle
{
  private: // coordinates of the left down corner
    int x_corn;
    int y_corn;
    // constructor
  public:
    ScreenRectangle(int w, int h, int x, int y) : Rectangle(w, h)
    {
        x_corn = x;
        y_corn = y;
    };
};

//ex4: RectangleTest
class RectangleTest
{
  public:
    void set_class()
    {
        ScreenRectangle rect_test(800, 30, 225, 120);
        Rectangle my_rect(1024, 768);
        bool fit = rect_test.get_X() > my_rect.get_X() && rect_test.get_X() > my_rect.get_Y();
        if (fit == true)
        {
            cout << "is 800x30 rectangle fit 1024x768 rectangle: yes" << endl;
        }
        else
        {
            cout << "is 800x30 rectangle fit 1024x768 rectangle: no" << endl;
        }
        cout << "area of my created rectangle 1024 x 768 is: " << my_rect.area() << endl;
        Rectangle rect_80x40(80, 40);
        cout << "area of my new created rectangle 80x40 is : " << rect_80x40.area() << endl;
    }
    
};

int main()
{
    RectangleTest rect;
    rect.set_class();
    return 0;
}
