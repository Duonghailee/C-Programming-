#include <iostream>
using namespace std;

class Calculator
{
  public:

  int Sum(int first, int second);
};

int Calculator::Sum(int first, int second)
{
  int sum =first + second;
  return sum;
}

// your code
class Printer {
    public:
    void Print();
};
void Printer::Print(){
    int num1, num2;
    cout<< "Give a first interger: ";
    cin>> num1;
    cout<< "Give a second integer: ";
    cin>> num2;
    Calculator newCal;
    int sum = newCal.Sum(num1,num2);
    cout<< "Sum: " <<sum<<endl;
}

int main()
{  
  Printer object;
  object.Print();
} 