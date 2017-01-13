#include <iostream> 
using namespace std;

//Step1. Abstract class Shape
class Shape
{
  public:
    virtual void draw() = 0;
};

//Step2. 3 concret classes based on Shape
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

/*******************************************/
//step3. abstract class Color
class Color
{
  public:
    virtual void fill() = 0;
};

// step4. concrete calss RED, GREEN, BLUE
class Red : public Color
{
  public:
    void fill()
    {
        cout << "Inside Red::fill() method." << endl;
    }
};

class Green : public Color
{
  public:
    void fill()
    {
        cout << "Inside Green::fill() method." << endl;
    }
};

class Blue : public Color
{
  public:
    void fill()
    {
        cout << "Inside Blue::fill() method." << endl;
    }
};

//step 5: create an abstract class to get factories for Color and Shape objects.
class AbstractFactory
{
  public:
    virtual Color *getColor(const char *color) = 0;
    virtual Shape *getShape(const char *shapeType) = 0;
};

//step 6: create Factory classed extending AbstractFactory to generate object of concrete class

class ShapeFactory : public AbstractFactory
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
        else
        {
            return new Circle; // default case, circle return
        }
    }
    Color *getColor(const char *color)
    {
        return NULL;
    }
};

//color Factory

class ColorFactory : public AbstractFactory
{
  public:
    Color *getColor(const char *color)
    {
        if (strcmp(color, "RED") == 0)
        {
            return new Red;
        }
        else if (strcmp(color, "GREEN") == 0)
        {
            return new Green;
        }
        else
        {
            return new Blue; // default case, Blue return
        }
    }

    Shape *getShape(const char *shapeType)
    {
        return NULL;
    }
};

//step 7: Create a factory generator/producer class to get factories by passing info Shape / color
class FactoryProducer
{
  public:
    AbstractFactory *getFactory(const char *type)
    {
        if (strcmp(type, "SHAPE") == 0)
        {
            return new ShapeFactory;
        }
        else
        {
            return new ColorFactory;
        }
    }
};

//step 8: use the factoryproducer to get AbstractFactory in order to get factories of concret class

int main()
{
    FactoryProducer factory;
    //get shape factory
    AbstractFactory *shapeFactory = factory.getFactory("SHAPE");

    //get an object of Shape Circle
    Shape *shape1 = shapeFactory->getShape("CIRCLE");

    //call draw method of Shape Circle
    shape1->draw();

    //get an object of Shape Rectangle
    Shape *shape2 = shapeFactory->getShape("RECTANGLE");

    //call draw method of Shape Rectangle
    shape2->draw();

    //get an object of Shape Square
    Shape *shape3 = shapeFactory->getShape("SQUARE");

    //call draw method of Shape Square
    shape3->draw();

    //get color factory
    AbstractFactory *colorFactory = factory.getFactory("COLOR");

    //get an object of Color Red
    Color *color1 = colorFactory->getColor("RED");

    //call fill method of Red
    color1->fill();

    //get an object of Color Green
    Color *color2 = colorFactory->getColor("GREEN");

    //call fill method of Green
    color2->fill();

    //get an object of Color Blue
    Color *color3 = colorFactory->getColor("BLUE");

    //call fill method of Color Blue
    color3->fill();

    return 0;
}
