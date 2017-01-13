#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/* Composite pattern */
//step 1: Create Employee class having list of Employee objects.
class Employee
{
  private:
    std::string name;
    std::string dept;
    int salary;
    deque<Employee *> subordinates;

  public:
    Employee(std::string new_name, std::string new_dept, int sal)
    {
        name = new_name;
        dept = new_dept;
        salary = sal;
    }

    void add(Employee *e)
    {
        subordinates.push_back(e);
    }

    void remove(Employee *e)
    {
        deque<Employee *>::iterator it;
        for (it = subordinates.begin(); it != subordinates.end(); ++it)
        {
            if (e == *it)
            {
                subordinates.erase(it);
            }
            
        }
    }

    deque<Employee *> getSubordinates()
    {
        return subordinates;
    }
    void print_info()
    {
        cout << "Employee :[ Name : " << name << ", dept : " << dept << " , salary :" << salary << " ]" << endl;
    }
};

//step 2: verify output
int main()
{
    Employee *CEO = new Employee("John", "CEO", 30000);
    Employee *headSales = new Employee("Robert", "Head Sales", 20000);
    Employee *headMarketing = new Employee("Michel", "Head Marketing", 20000);
    Employee *clerk1 = new Employee("Laura", "Marketing", 10000);
    Employee *clerk2 = new Employee("Bob", "Marketing", 10000);

    Employee *salesExecutive1 = new Employee("Richard", "Sales", 10000);
    Employee *salesExecutive2 = new Employee("Rob", "Sales", 10000);

    CEO->add(headSales);
    CEO->add(headMarketing);

    headSales->add(salesExecutive1);
    headSales->add(salesExecutive2);

    headMarketing->add(clerk1);
    headMarketing->add(clerk2);


    //Print info of the organization
    CEO->print_info();
    for (Employee *e : CEO->getSubordinates())
    {
        e->print_info();
        for (Employee *p : e->getSubordinates())
        {
            p->print_info();
        }
    }
    return 0;
}
