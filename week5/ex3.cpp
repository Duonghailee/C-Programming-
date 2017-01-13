#include <iostream>
using namespace std;

class number
{
  protected:
    int val;

  public:
    void set_value(int value)
    {
        val = value;
    }
    virtual void show(){};
};

// derived class
class hextype : public number
{
  public:
    void show()
    {
        std::printf("%x\n", val);
    }
};

//class dec
class dectype : public number
{
  public:
    void show()
    {
        std::printf("%d\n", val);
    }
};

//  class oct
class octtype : public number
{
  public:
    void show()
    {
        std::printf("%o\n", val);
    }
};

int main()
{
    dectype dec;
    hextype hex;
    octtype oct;

    //input data 20
    dec.set_value(20);
    hex.set_value(20);
    oct.set_value(20);

    // show result
    dec.show();
    hex.show();
    oct.show();
}