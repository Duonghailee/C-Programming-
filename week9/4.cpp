#include <iostream>
#include <string>
#include <stdlib.h> //srand, rand
#include <time.h> //time seed
#include <map> //std::insert, std::find
using namespace std;

/* Flyweiht pattern */

//step 1:
class Shape
{
  public:
    virtual void draw() = 0;
};

//step 2: Create concrete class implementing the same interface.
class Circle : public Shape
{
  protected:
    int x, y, radius;
    string color;

  public:
    Circle(string new_color)
    {
        color = new_color;
    }

    void setX(int x0)
    {
        x = x0;
    }

    void setY(int y0)
    {
        y = y0;
    }

    void setRadius(int r)
    {
        radius = r;
    }

    void draw()
    {
        cout << "Circle: Draw() [Color: " << color << " <<, x : " << x << ", y : " << y << ", radius : " << radius << "]" << endl;
    }
};

//step 3: Create a factory to generate object of concrete class based on given information.
class ShapeFactory
{
  private:
    map<string, Shape *> circleMap;

  public:
    Shape *getCircle(string color)
    {
        Shape *circle;
        if (circleMap.find(color) == circleMap.end())
        {
            circle = new Circle(color);
            circleMap.insert(make_pair(color, circle));
            cout << "Creating circle of color : " << color << endl;
            return circle;
        }
        else
        {
            circle = circleMap.at(color);
            return circle;
        }
    }
};
int getRandomX()
{
    int random = rand() % 100 + 1;
    return random;
};

int getRandomY()
{
    int random = rand() % 100 + 1;
    return random;
};

string getRandomColor()
{
    string color[] = {"Red", "Green", "Blue", "White", "Black"};
    int random = rand() % 5;
    return color[random];
};
//step 4: verify outputs
int main()
{
    srand(time(NULL)); //set the seeds
    ShapeFactory *shapeFactory = new ShapeFactory;
    for (int i = 0; i < 20; ++i)
    {
        Circle *circle = (Circle *)shapeFactory->getCircle(getRandomColor());
        circle->setX(getRandomX());
        circle->setY(getRandomY());
        circle->setRadius(100);
        circle->draw();
    }
    return 0;
}
