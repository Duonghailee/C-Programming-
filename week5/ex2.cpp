#include <iostream>
using namespace std;

class Shape
{
  protected:
    float l;

  public:
    void getData()
    {
        cin >> l;
    }
    virtual float calculateArea() = 0;
};

//derived class Squares
class Square : public Shape
{
  public:
    float calculateArea()
    {
        return l * l;
    }
};

// class Circle
class Circle : public Shape
{
  public:
    float calculateArea()
    {
        return 3.14 * l * l;
    }
};

int main()
{
    Circle cir;
    Square squ;

    cout << "Enter length to calculate the area of a square: ";
    squ.getData();
    cout << "Area of square: " << squ.calculateArea() << endl;
    
    cout << "Enter radius to calculate the area of a circle: ";
    cir.getData();
    cout << "Area of circle: " << cir.calculateArea() << endl;
}
