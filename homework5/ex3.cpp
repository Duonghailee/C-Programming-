
#include <iostream>
using namespace std;

//base class Area
class Area
{

  public:
    void area_calc(double length, double breadth)
    {
        cout << "Area = " << (length * breadth) << endl;
    }
};

//another base class
class Perimeter
{

  public:
    void peri_calc(double length, double breadth)
    {
        cout << "Perimeter = " << 2*(length + breadth) << endl;
    }
};

// class rectangle
class Rectangle : public Area, public Perimeter
{
  private:
    double length, breadth;

  public:
    void get_data()
    {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }
    void area_calc()
    {
        Area::area_calc(length, breadth);
    }
    void peri_calc()
    {
        Perimeter::peri_calc(length, breadth);
    }
};

// main program
int main()
{
    Rectangle rec;
    rec.get_data();
    rec.area_calc();
    rec.peri_calc();
}
