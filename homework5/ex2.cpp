
#include <iostream>
using namespace std;

//base class student
class student
{
  private:
    char school[80];
    char degree[80];

  public:
    void getedu()
    {
        cout << "Enter name of school or University: ";
        cin >> school;
        cout << "Enter highest degree earned: \n(Highschool, Bachelor's, Master's, PhD): ";
        cin >> degree;
    }
    void putedu()
    {
        cout << "Name of school/Uni: " << school << endl;
        cout << "Degree: " << degree << endl;
    }
};

//another base class
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
        cout << "Enter number:";
        cin >> number;
    }
    void putdata()
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

// derived class manager
class manager : public employee, public student
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
        student::getedu();
    }
    void putdata()
    {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf club dues: " << dues << endl;
        student::putedu();
    }
};

//derived class
class scientist : public employee, public student
{
  private:
    int pubs;

  public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of pubs: ";
        cin >> pubs;
        student::getedu();
    }
    void putdata()
    {
        employee::putdata();
        cout << "Number of publications: " << pubs << endl;
        student::putedu();
    }
};

//class laborer
class laborer : public employee
{
};

int main()
{
    manager m1;
    scientist s1, s2;
    laborer l1;

    cout << "Enter data for manager 1" << endl;
    m1.getdata();
    cout << endl;

    cout << "Enter data for sicentist 1" << endl;
    s1.getdata();
    cout << endl;

    cout << "Enter data for sicentist 2" << endl;
    s2.getdata();
    cout << endl;

    cout << "Enter data for laborer 1" << endl;
    l1.getdata();
    cout << endl;

    cout << "------------------\n\n";

    cout << "Data on manager 1" << endl;
    m1.putdata();
    cout << endl;

    cout << "Data on scientist 1" << endl;
    s1.putdata();
    cout << endl;

    cout << "Data on scientist 2" << endl;
    s2.putdata();
    cout << endl;

    cout << "Data on laborer 1" << endl;
    l1.putdata();
    cout << endl;
    return 0;
}

/* solutions :
//empmult.cpp
//multiple inheritance with employees and degrees
#include <iostream>
using namespace std;
const int LEN = 80;           //maximum length of names
////////////////////////////////////////////////////////////////
class student                 //educational background
   {
   private:
      char school[LEN];       //name of school or university
      char degree[LEN];       //highest degree earned
   public:
      void getedu()
         {
         cout << "   Enter name of school or university: ";
         cin >> school;
         cout << "   Enter highest degree earned \n";
         cout << "   (Highschool, Bachelor's, Master's, PhD): ";
         cin >> degree;
         }
      void putedu() const
         {
         cout << "\n   School or university: " << school;
         cout << "\n   Highest degree earned: " << degree;
         }
   };
////////////////////////////////////////////////////////////////
class employee
   {
   private:
      char name[LEN];         //employee name
      unsigned long number;   //employee number
   public:
      void getdata()
         {
         cout << "\n   Enter last name: "; cin >> name;
         cout << "   Enter number: ";      cin >> number;
         }
      void putdata() const
         {
         cout << "\n   Name: " << name;
         cout << "\n   Number: " << number;
         }
   };
////////////////////////////////////////////////////////////////
class manager : private employee, private student  //management
   {
   private:
      char title[LEN];        //"vice-president" etc.
      double dues;            //golf club dues
   public:
      void getdata()
         {
         employee::getdata();
         cout << "   Enter title: ";          cin >> title;
         cout << "   Enter golf club dues: "; cin >> dues;
         student::getedu();
         }
      void putdata() const
         {
         employee::putdata();
         cout << "\n   Title: " << title;
         cout << "\n   Golf club dues: " << dues;
         student::putedu();
         }
   };
////////////////////////////////////////////////////////////////
class scientist : private employee, private student  //scientist
   {
   private:
      int pubs;     //number of publications
   public:
      void getdata()
         {
         employee::getdata();
         cout << "   Enter number of pubs: "; cin >> pubs;
         student::getedu();
         }
      void putdata() const
         {
         employee::putdata();
         cout << "\n   Number of publications: " << pubs;
         student::putedu();
         }
   };
////////////////////////////////////////////////////////////////
class laborer : public employee             //laborer
   {
   };
////////////////////////////////////////////////////////////////
int main()
   {
   manager m1;
   scientist s1, s2;
   laborer l1;

   cout << endl;
   cout << "\nEnter data for manager 1";    //get data for
   m1.getdata();                            //several employees

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for scientist 2";
   s2.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

   cout << "\nData on manager 1";           //display data for
   m1.putdata();                            //several employees

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on scientist 2";
   s2.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   cout << endl;
   return 0;
   }
*/