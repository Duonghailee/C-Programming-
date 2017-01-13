#include <iostream>
using namespace std;
class test
{
  public:
    // case int
    test(int a)
    {
        cout << "Result: " << a << endl;
    }

    // case float
    test(float b)
    {
        cout << "Result: " << b << endl;
    }

    // case 3 int, double
    test(int a, float b)
    {
        cout << "Result: " << (a + b) << endl;
    }
};
int main()
{
    int x = 5;
    float y = 5.5;
    test test1(x);
    test test2(y);
    test test3(x, y);
    return 0;
}