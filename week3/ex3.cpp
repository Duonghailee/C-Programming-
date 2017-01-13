#include <iostream>
using namespace std;

class Animal
{
  protected:
    string name;
    int age;

  public:
    void set_value(string new_name, int new_age)
    {
        name = new_name;
        age = new_age;
    }
};
// zebra class derivate
class Zebra : public Animal
{

  public:
    void print_info(){
        cout<<"The zebrea named "<<name<<" is "<<age<<" years old."<<" The zebra comes from Africa"<<endl;
    }
};

// dolphine class derivate
class Dolphin : public Animal
{

  public:
    void print_info(){
        cout<<"The dolphin named "<<name<<" is "<<age<<" years old."<<" The dolphin comes from New Zeland"<<endl;
    }
};


int main()
{
    Zebra horse;
    Dolphin hai;
    horse.set_value("hihi",12);
    hai.set_value("haha",6);
    horse.print_info();
    hai.print_info();
    return 0;
}