#include <iostream>
using namespace std;

template <class T>
T Large(T &a, T &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    // or: return (a>b)? a:b;
}
int main()
{
    int i1, i2;
    float f1, f2;
    char c1, c2;
    cout << "Enter two integers: " << endl;
    cin >> i1;
    cin >> i2;
    cout << Large<int>(i1, i2) << " is larger." << endl;

    cout << "Enter two floating-point numbers: " << endl;
    cin >> f1;
    cin >> f2;
    cout << Large<float>(f1, f2) << " is larger." << endl;

    cout << "Enter two characters: " << endl;
    cin >> c1;
    cin >> c2; // must seperate by space, enter does not work
    cout << Large<char>(c1, c2) << " has larger ASSCII value." << endl;
    return 0;
}
