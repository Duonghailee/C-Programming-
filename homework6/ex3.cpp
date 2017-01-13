#include <iostream>
using namespace std;
#define MAX 100

//abstract class
class person
{
  protected:
    char name[50];

  public:
    void getName()
    {
        cout << "   Enter name: ";
        cin >> name;
    }
    void putName()
    {
        cout << "Name is: " << name << endl;
    }

    //virtual function
    virtual void getData()
    {
    }
    virtual bool isOutstanding() = 0;
};

//derived class  student
class student : public person
{
  protected:
    double gpa;

  public:
    void getData()
    {
        person::getName();
        cout << "   Enter student's GPA: ";
        cin >> gpa;
    }
    bool isOutstanding()
    {
        if (gpa > 3.5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//derived class professor
class professor : public person
{
  protected:
    int numPubs;

  public:
    void getData()
    {
        person::getName();
        cout << "   Enter number of professor's publication: ";
        cin >> numPubs;
    }
    bool isOutstanding()
    {
        if (numPubs > 100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    char quit;
    char ans;
    person *myPerson[MAX]; // array store pointers which point
    person *personPointer; //temp pointer
    int i = 0; // number of person in list
    while (quit != 'n')
    {
        cout << "Enter student or professor (s/p): ";
        cin >> ans;
        if (ans == 's')
        {
            personPointer = new student; 
            personPointer->getData();
            myPerson[i] = personPointer;
            cout << "   Enter another(y/n)? ";
            cin >> quit;
        }
        else if (ans == 'p')
        {
            personPointer = new professor;
            personPointer->getData();
            myPerson[i] = personPointer;
            cout << "   Enter another(y/n)? ";
            cin >> quit;
        }
        i++;
    }
    cout << endl;
    for (int j = 0; j < i; j++)
    {
        myPerson[j]->putName();
        if (myPerson[j]->isOutstanding() == true)
        {
            cout << "   This person is outstanding" << endl;
        }
    }
    return 0;
}

/*
// virtpers.cpp [Laf02, p. 512]
// virtual functions with person class
#include <iostream>
using namespace std;
//****************************************************************************
class person //person class
{
	protected:
		char name[40];
	public:
		void getName()
			{ cout << " Enter name: "; cin >> name; }
		void putName()
			{ cout << "Name is: " << name << endl; }
		virtual void getData() = 0; //pure virtual func
		virtual bool isOutstanding() = 0; //pure virtual func
};
/*****************************************************************************
class student : public person //student class
{
	private:
		float gpa; //grade point average
	public:
		void getData() //get student data from user
		{
			person::getName();
			cout << " Enter student's GPA: "; cin >> gpa;
		}
		bool isOutstanding()
			{ return (gpa > 3.5) ? true : false; }
};
//*****************************************************************************
class professor : public person //professor class
{
	private:
		int numPubs; //number of papers published
	public:
		void getData() //get professor data from user
		{
			person::getName();
			cout << " Enter number of professor’s publications: ";
			cin >> numPubs;
		}
		bool isOutstanding()
			{ return (numPubs > 100) ? true : false; }
};
//*****************************************************************************
int main()
{
	person* persPtr[100]; //array of pointers to persons
	int n = 0; //number of persons on list
	char choice;
	do {
		cout << "Enter student or professor (s/p): ";
		cin >> choice;
		if(choice=='s') //put new student
			persPtr[n] = new student; // in array
		else //put new professor
			persPtr[n] = new professor; // in array
		persPtr[n++]->getData(); //get data for person
		cout << " Enter another (y/n)? "; //do another person?
		cin >> choice;
	} while( choice=='y' ); //cycle until not ‘y’

	for(int j=0; j<n; j++) //print names of all
	{ //persons, and
		persPtr[j]->putName(); //say if outstanding
		if( persPtr[j]->isOutstanding() )
			cout << " This person is outstanding\n";
	}
	return 0;
} //end main()
*/
