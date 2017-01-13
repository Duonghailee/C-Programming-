#include <iostream>
using namespace std;

/* Brigde pattern */
//step 1: DrawAPI interface
class DrawAPI
{
  public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

//class to extend DrawAPI
class temp_draw : public DrawAPI
{
    void drawCircle(int radius, int x, int y)
    {
    }
};
// step 2: Create concrete bridge implementer classes implementing the DrawAPI interface.
class RedCircle : public DrawAPI
{
  public:
    void drawCircle(int radius, int x, int y)
    {
        cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
    }
};

class GreenCircle : public DrawAPI
{
  public:
    void drawCircle(int radius, int x, int y)
    {
        cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
    }
};

//step 3: Create an abstract class Shape 
class Shape
{
  public:
    virtual void draw() = 0;
};

//step 4: Create concrete class implementing the Shape interface.
class Circle : public Shape
{
  protected:
    int x, y, radius;
    DrawAPI *p; //pointer of DrawAPI interface to red or green circle

  public:
    Circle(int x0, int y0, int r, DrawAPI *drawAPI) : p(drawAPI)
    {
        x = x0;
        y = y0;
        radius = r;
    }

  public:
    void draw()
    {
        p->drawCircle(radius, x, y);
    }
};

//step 5: verify result
int main()
{
    DrawAPI *red = new RedCircle();
    DrawAPI *green = new GreenCircle();
    Shape *redCircle = new Circle(100, 100, 10, red);
    Shape *greenCircle = new Circle(100, 100, 10, green);
    redCircle->draw();
    greenCircle->draw();

    return 0;
}