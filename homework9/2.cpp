#include <iostream>
using namespace std;

/*Prototye pattern*/


//step 1 : cloneable abstract class
class cloneable
{
  protected:
    std::string type;

  private:
    std::string id;

  public:
    virtual void draw() = 0;
    virtual cloneable *clone() = 0;

    //type and set id for object cloneable
    std::string getType()
    {
        return type;
    }

    std::string getid()
    {
        return id;
    }
    void setid(std::string ID)
    {
        id = ID;
    }
};

//step 2: concret classes declare
class Rectangle : public cloneable
{
  public:
    Rectangle()
    {
        type = "Rectangle";
    }

    void draw()
    {
        cout << "Inside Rectangle::draw() method." << endl;
    }

    cloneable *clone()
    {
        return new Rectangle(*this);
    }
};

class Square : public cloneable
{
  public:
    Square()
    {
        type = "Square";
    }

    void draw()
    {
        cout << "Inside Square::draw() method." << endl;
    }

    cloneable *clone()
    {
        return new Square(*this);
    }
};

class Circle : public cloneable
{
  public:
    Circle()
    {
        type = "Circle";
    }

    void draw()
    {
        cout << "Inside Circle::draw() method." << endl;
    }
    cloneable *clone()
    {
        return new Circle(*this);
    }
};

// step 3, factory that manages Shape prototpe instance and produces their clones
class ShapeCache
{
  protected:
    static cloneable *circle;
    static cloneable *square;
    static cloneable *rectangle;

  public:
    static void loadCache()
    {
        circle = new Circle();
        circle->setid("1");

        square = new Square();
        square->setid("2");

        rectangle = new Rectangle();
        rectangle->setid("3");
    }

    static cloneable *getCircle()
    {
        return circle->clone();
    }

    static cloneable *getSquare()
    {
        return square->clone();
    }

    static cloneable *getRectangle()
    {
        return rectangle->clone();
    }
};

// delete cache
cloneable *ShapeCache::circle = 0;
cloneable *ShapeCache::square = 0;
cloneable *ShapeCache::rectangle = 0;

//step 4: test with main class
int main()
{
    ShapeCache::loadCache();
    cloneable *shape;

    shape = ShapeCache::getCircle();
    cout << "Shape: " << shape->getType() << endl;

    shape = ShapeCache::getSquare();
    cout << "Shape: " << shape->getType() << endl;

    shape = ShapeCache::getRectangle();
    cout << "Shape: " << shape->getType() << endl;

    return 0;
}
