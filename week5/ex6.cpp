#include <iostream>
#define SIZE 100
using namespace std;

class stack
{
  private:
    char array[SIZE]; //holds the stack
    int tos;          // index of top-of-stack

  public:
    stack()
    {
        tos = -1;
    }
    void push(char num); // push element
    void pop();          // remove first element
    int show(int index); // show element_type
    int size();          // size of stack
};

void stack::push(char num)
{
    if (tos == SIZE)
    {
        cout << "stack full" << endl;
    }
    else
    {
        tos++;
        array[tos] = num;
    }
}

void stack::pop()
{
    if (tos == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        array[tos] = '\0';
        tos--;
    }
}

char stack::show(int index)
{
    if (index > tos)
    {
        cout << "Over bound<" << endl;
        return 0;
    }
    else
    {
        return array[tos - index];
    }
}

int stack::size()
{
    return tos;
}

//main fuction
int main()
{
    char input;
    int number;
    stack RPN;
    cout << "Give RPN-expression vertically:\n\n";
    while (input != '=')
    {
        input = getchar();
        if (input != '+' && input != '-' && input != '*')
        {
            RPN.push(input);
        }
        else if (input == '+')
        {
            int size = RPN.size();
            char temp = stack.show(size) + stack.show(size - 1);
            RPN.pop();
            RPN.pop();
            RPN.push(temp);
        }

         else if (input == '-')
        {
            int size = RPN.size();
            char temp = stack.show(size) - stack.show(size - 1);
            RPN.pop();
            RPN.pop();
            RPN.push(temp);
        }

         else if (input == '*')
        {
            int size = RPN.size();
            char temp = stack.show(size) * stack.show(size - 1);
            RPN.pop();
            RPN.pop();
            RPN.push(temp);
        }
    }
    
    s1.push('a');
    s1.push('b');
    s1.push('c');
    for (int i = 0; i <= s1.size(); i++)
    {
        cout << "Pop s1: " << s1.show(i) << endl;
    }

    s2.push('x');
    s2.push('y');
    s2.push('z');
    for (int i = 0; i <= s2.size(); i++)
    {
        cout << "Pop s2: " << s2.show(i) << endl;
    }

    //DOUBLE stack
    stack<double> ds1;
    stack<double> ds2;

    ds1.push(1.1);
    ds1.push(3.3);
    ds1.push(5.5);
    for (int i = 0; i <= ds1.size(); i++)
    {
        cout << "Pop ds1: " << ds1.show(i) << endl;
    }

    ds2.push(2.2);
    ds2.push(4.4);
    ds2.push(6.6);
    for (int i = 0; i <= ds2.size(); i++)
    {
        cout << "Pop ds2: " << ds2.show(i) << endl;
    }

    return 0;
}
