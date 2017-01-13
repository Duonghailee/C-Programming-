#include <iostream>
using namespace std;

//base class
class base
{
  protected:
  public:
    virtual void vfunc()
    {
        cout << "This is base's vfunc()." << endl;
    }
};

//derived1 class
class derived1 : public base
{
  public:
   void vfunc()
    {
         cout << "This is derived1's vfunc()." << endl;
    }
};


//derived1 class
class derived2 : public base
{
  public:
    void vfunc()
    {
         cout << "This is derived2's vfunc()." << endl;
    }
};

int main()
{
    base *p, b;
    derived1 d1;
    derived2 d2;
    b.vfunc();
    d1.vfunc();
    d2.vfunc();
    return 0;
}