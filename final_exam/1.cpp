#include <iostream>
#include <stack>
using namespace std;

//main fuction
int main()
{
    stack<int> RPN;
    int number;
    char input;
    cout << "Give RPN-expression vertically:\n\n";
    while (input != '=')
    {
        cin >> input;
        number = input - '0';
        if (input != '+' && input != '-' && input != '*')
        {
            RPN.push(number);
        }
        else if (input == '+')
        {
            int a = RPN.top();
            RPN.pop();
            int b = RPN.top();
            RPN.pop();
            int temp = a + b;
            RPN.push(temp);
        }

        else if (input == '-')
        {
            int a = RPN.top();
            RPN.pop();
            int b = RPN.top();
            RPN.pop();
            int temp = b - a;
            RPN.push(temp);
        }

        else if (input == '*')
        {
            int a = RPN.top();
            RPN.pop();
            int b = RPN.top();
            RPN.pop();
            int temp = a * b;
            RPN.push(temp);
        }
    }
    RPN.pop();
    cout << RPN.top() << endl;

    return 0;
}
