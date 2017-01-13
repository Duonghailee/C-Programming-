#include <iostream>
using namespace std;

//base class
class Person
{
  private:
    char name[50];
    char gender[50];
    int age;

  public:
    void getdata()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

//derived class
class Student : public Person
{
  private:
    char institute[100];
    char level[50];

  public:
    void getdata()
    {
        Person::getdata();
        cout << "Name of College/School: ";
        cin >> institute;
        cout << "Level: ";
        cin >> level;
        cout << endl;
    }
    void display()
    {
        Person::display();
        cout << "Name of College/School: " << institute << endl;
        cout << "Level: " << level << endl;
        cout <<endl;
    }
};

//derived class
class Employee : public Person
{
  private:
    char company[50];
    char salary[50];

  public:
    void getdata()
    {
        Person::getdata();
        cout << "Name of Company: ";
        cin >> company;
        cout << "Salary: ";
        cin >> salary;
        cout << endl;
    }

    void display()
    {
        Person::display();
        cout << "Name of Company " << company << endl;
        cout << "Salary: " << salary << endl;
        cout<< endl;
    }
};

int main()
{
    Student stu;
    Employee employ;
    cout << "Student" << endl;
    cout << "Enter data" << endl;
    stu.getdata();
    cout << "Displaying data" << endl;
    stu.display();

    cout << "Employee" << endl;
    cout << "Enter data" << endl;
    employ.getdata();
    cout << "Displaying data" << endl;
    employ.display();
    return 0;
}