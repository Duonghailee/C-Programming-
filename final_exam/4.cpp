#include <iostream>
using namespace std;

class Point
{
    int x, y;

  public:
    Point() { x = y = 0; }
    Point(int i, int j)
    {
        x = i;
        y = j;
    };

    Point operator++();                        // prefix version of ++
    Point operator+(Point &anotheObject);      // + version
    Point operator-(Point &anotheObject);      // - version
    void operator=(const Point &anotheObject); // = version

    void show();
};

// Overload the prefix version of ++.
Point Point::operator++() // Overload ++ for Point
{
    x++; // increment x, y
    y++;
    return *this; // Return the incremented object.
}

// Overload the + version
Point Point::operator+(Point &anotherObject)
{
    x += anotherObject.x;
    y += anotherObject.y;
    return *this;
}

// Overload the - version
Point Point::operator-(Point &anotherObject)
{
    x -= anotherObject.x;
    y -= anotherObject.y;
    return *this;
}

// Overload the = version
void Point::operator=(const Point &anotherObject)
{
    x = anotherObject.x;
    y = anotherObject.y;
}

// Show X, Y coordinates.
void Point::show()
{
    cout << "(" << x << "," << y << ")" << endl;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cout << "Give a x-coordinate of point1: ";
    cin >> x1;
    cout << "Give a y-coordinate of point1: ";
    cin >> y1;
    Point p1(x1, y1);

    cout << "Give a x-coordinate of point2: ";
    cin >> x2;
    cout << "Give a y-coordinate of point2: ";
    cin >> y2;
    Point p2(x2, y2);

    cout << "Give a x-coordinate of point3: ";
    cin >> x3;
    cout << "Give a y-coordinate of point3:\n ";
    cin >> y3;
    Point p3(x3, y3);

    //first Operation
    cout << "point1: ";
    p1.show();
    ++p1;
    cout << "point1: ";
    p1.show();

    //second Operation

    cout << "\npoint1: ";
    p1.show();
    cout << "Point2: ";
    p2.show();

    p2 = ++p1;
    cout << "point1: ";
    p1.show();
    cout << "Point2: ";
    p2.show();


    //Third operation
    cout << "\npoint1: ";
    p1.show();
    cout << "Point3: ";
    p3.show();
    Point temp1 = p1 + p3;
    p1 = temp1;
    cout << "point1: ";
    p1.show();
    cout << "Point3: ";
    p3.show();

    //Fourth operation

    cout << "\npoint1: ";
    p1.show();
    cout << "Point3: ";
    p3.show();
    Point temp2 = p1 - p3;
    p1 = temp2;
    cout << "point1: ";
    p1.show();
    cout << "Point3: ";
    p3.show();

    //Fifth operation

    cout << "\npoint1: ";
    p1.show();
    cout << "Point2: ";
    p2.show();
    cout << "Point3: ";
    p3.show();

    p2 = p3;
    p1 = p2;
    cout << "point1: ";
    p1.show();
    cout << "Point2: ";
    p2.show();
    cout << "Point3: ";
    p3.show();

    return 0;
}