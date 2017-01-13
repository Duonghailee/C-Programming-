#include <iostream>
using namespace std;

//Strategy Pattern
//step 1: Create an interface
class Strategy
{
  public:
    virtual int doOperation(int num1, int num2) = 0;
};

//step2: Create concrete classes implementing the same interface.
//Operation Add
class OperationAdd : public Strategy
{
  public:
    int doOperation(int num1, int num2)
    {
        return num1 + num2;
    }
};

//Operation substract
class OperationSubstract : public Strategy
{
  public:
    int doOperation(int num1, int num2)
    {
        return num1 - num2;
    }
};

//Operation Multiply
class OperationMultiply : public Strategy
{
  public:
    int doOperation(int num1, int num2)
    {
        return num1 * num2;
    }
};

//step3: Create context class
class Context
{
  private:
    Strategy *strategy;

  public:
    Context(Strategy *new_strategy)
    {
        strategy = new_strategy;
    }

    int executeStrategy(int num1, int num2)
    {
        return strategy->doOperation(num1, num2);
    }
};

//step4: verify ouput
int main()
{

    Context *context = new Context(new OperationAdd());
    cout << "10 + 5 = " << context->executeStrategy(10, 5) << endl;

    context = new Context(new OperationSubstract());
    cout << "10 - 5 = " << context->executeStrategy(10, 5) << endl;

    context = new Context(new OperationMultiply());
    cout << "10 * 5 = " << context->executeStrategy(10, 5) << endl;

    return 0;
}