#include <iostream>
using namespace std;

class SumOfNum
{
  public:
    int num1, num2;
    SumOfNum(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }
    void sum()
    {
        cout << "numbers initialized" << endl
             << "The addition result on:" << (num1 + num2) << endl;
    }
};

int main()
{
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    SumOfNum example(x, y);
    example.sum();
    return 0;
}