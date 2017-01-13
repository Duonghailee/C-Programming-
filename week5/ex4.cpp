#include <iostream>
using namespace std;

template <class X>
void swapargs(X &a, X &b)
{
    X c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';

    cout << "Original i, j: " << i << " " << j << endl;
    cout << "Original x, y: " << x << " " << y << endl;
    cout << "Original a, b: " << a << " " << b << endl;

    cout << "Inside swapargs int specilization." << endl;
    swapargs<int>(i, j);
    cout << "Inside template swapargs." << endl;
    swapargs<double>(x, y);
    cout << "Inside template swapargs." << endl;
    swapargs<char>(a, b);

    cout << "Swapped i, j: " << i << " " << j << endl;
    cout << "Swapped x, y: " << x << " " << y << endl;
    cout << "Swapped a, b: " << a << " " << b << endl;
}