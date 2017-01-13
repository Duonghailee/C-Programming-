#include <iostream>
using namespace std;

// base class
class Staff
{
  private:
    char name[50];
    int code;

  public:
    void getdata()
    {
        cout << "Enter data" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Code: ";
        cin >> code;
    }
    void display()
    {
        cout <<endl<<"Display data"<<endl;
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

//derived class
class Typist : public Staff
{
  private:
    int speed;

  public:
    //getdata method
    void getdata()
    {
        //call fuction getdata from base classic
        Staff::getdata();
        cout << "Speed: ";
        cin >> speed;
    }

    void display()
    {
        Staff::display();
        cout << "Speed: " << speed << endl;
    }
};

int main()
{
    Typist test;
    test.getdata();
    test.display();
    return 0;
}
