#include <iostream>
using namespace std;

//base class
class Liquid
{
  private:
    double specific_gravity;

  public:
    void input()
    {
        cout << "Specific gravity: ";
        cin >> specific_gravity;
    }
    void output()
    {

        cout << "Specific gravity: " << specific_gravity << endl;
    }
};

// derived class
class Fuel
{
  private:
    char rate[10];

  public:
    void input()
    {
        cout << "Rate(per liter): ";
        cin >> rate;
    }
    void output()
    {
        cout << "Rate(per liter): " << rate << endl;
    }
};

class Petrol : public Liquid, public Fuel
{
  public:
    void input()
    {
        Liquid::input();
        Fuel::input();
    }
    void output()
    {
        Liquid::output();
        Fuel::output();
    }
};

int main()
{
    Petrol petro;
    cout << "Enter data" << endl;
    petro.input();
    cout << endl;
    cout << "Displaying data" << endl;
    petro.output();
    return 0;
}
