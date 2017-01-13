#include <iostream>
using namespace std;

//base class
class Father
{
  protected:
    int a;

  public:
    Father()
    {
        a = 5;
    }
};

//derived class
class Son : public Father
{
  protected:
    int b;

  public:
    Son()
    {
        b = 9;
    }
};

//derived class
class GrandSon : public Son
{
  private:
    int c;

  public:
    GrandSon()
    {
        c = a + b;
    }

    void show()
    {
        cout << "a + b = "<< c << endl;
    }
};

int main()
{
    GrandSon grand_son;
    grand_son.show();

}
