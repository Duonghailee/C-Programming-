#include <iostream>
using namespace std;

//base class
class employee
{
  private:
    char name[80];
    unsigned long int number;

  public:
    void getdata()
    {
        cout << "Enter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata()
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

//derived class
class manager : public employee
{
  private:
    char title[80];
    double dues;

  public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues:";
        cin >> dues;
    }
    void putdata()
    {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf club dues: " << dues << endl;
    }
};

//derived class
class scientist : public employee
{
  private:
    int pubs;

  public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of pubs: ";
        cin >> pubs;
    }
    void putdata()
    {
        employee::putdata();
        cout << "Number of publications: " << pubs << endl;
    }
};

//class laborer
class laborer : public employee
{
};

int main()
{
    manager m1, m2;
    scientist s1;
    laborer l1;

    cout << "Enter data for manager 1" << endl;
    m1.getdata();
    cout << endl;

    cout << "Enter data for manager 2" << endl;
    m2.getdata();
    cout << endl;

    cout << "Enter data for sicentist 1" << endl;
    s1.getdata();
    cout << endl;

    cout << "Enter data for laborer 1" << endl;
    l1.getdata();
    cout << endl;

    cout << "------------------"<<"\n";

    cout << "Data on manager 1" << endl;
    m1.putdata();
    cout << endl;

    cout << "Data on manager 2" << endl;
    m2.putdata();
    cout << endl;

    cout << "Data on scientist 1" << endl;
    s1.putdata();
    cout << endl;

    cout << "Data on laborer 1" << endl;
    l1.putdata();
    cout << endl;
    return 0;
}
