#include <iostream>
using namespace std;

class Mother
{
  public:
    void display()
    {
        cout << "Mother: display function" << endl;
    }
};
class Daughter : public Mother
{
  public:
    void display()
    {
        cout << "daughter: display function" << endl;
    }
};

int main()
{
    Daughter girl;
    girl.display();
    return 0;
}