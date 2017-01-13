#include <iostream>
#include <string>
using namespace std;

class Point
{
  private:
    int x, y;

  public:
    Point(int x0; int y0);
    void setValue(int x1, int y1)
    {
        x=x1;
        y=y1;
    }
    Point operator+(Point &anotheObject);
    Point operator-(Point &anotheObject);
    Point operator=(Point &anotheObject);
    Point operator++();
    void show();
    
};

Point Point::operator+(Point &anotherObject)
{
    Point temp;
    this->x = this->x + anotherObject.x;
    this->y = this->y + anotherObject.y;
    return *this;
}

Point Point::operator-(Point &anotherObject)
{
    Point temp;
    temp.x = this->x - anotherObject.x;
    temp.y = this->y - anotherObject.y;
    return temp;
}

Point Point::operator=(Point &anotherObject)
{
    Point temp;
    temp.x = anotherObject.x;
    temp.y = anotherObject.y;
    return temp;
}

Point Point::operator++()
{
    Point p(x,y);
    x++;
    y++;
    return p;
}

void Point::show()
{
    cout << "(" << x << "," << y << ")" << endl;
};

int main()
{
    Point point1, point2, point3;
    int x1, y1, x2, y2, x3, y3;
    cout << "Give a x-coordinate of point1: ";
    cin >> x1;
    cout << "Give a y-coordinate of point1: ";
    cin >> y1;
    point1.setValue(x1, y1);

    cout << "Give a x-coordinate of point2: ";
    cin >> x2;
    cout << "Give a y-coordinate of point2: ";
    cin >> y2;
    point2.setValue(x2, y2);

    cout << "Give a x-coordinate of point3: ";
    cin >> x3;
    cout << "Give a y-coordinate of point3: ";
    cin >> y3;
    point3.setValue(x3, y3);

    cout<<"point1: ";
    point1.show();
    point1++;
    point1.show();
    return 0;
}