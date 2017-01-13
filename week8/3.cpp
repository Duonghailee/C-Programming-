#include <iostream>
using namespace std;

//step1: create singleobject class
class SingleObject
{
  private:
    //create an object of a singleobject, instance
    static SingleObject instance;
    SingleObject(){}; //constructor private so that this class can not be insttantiated

  public:
    static SingleObject getInstance()
    {
        return instance;
    }
    void showMessage()
    {
        cout << "Hello World!" << endl;
    }
};

//step2: test singletonObject
int main()
{
    SingleObject object = SingleObject::getInstance();
    object.showMessage();
    //  SingleObject ob2; this will not work since constructor is private

    return 0;
}