#include <iostream>
#include <string>
using namespace std;

//MVC pattern
//step1: Create model
class Student
{
  private:
    string rollNo;
    string name;

  public:
    string getRollNo()
    {
        return rollNo;
    }

    void setRollNo(string new_rollNo)
    {
        rollNo = new_rollNo;
    }
    string getName()
    {
        return name;
    }

    void setName(string new_name)
    {
        name = new_name;
    }
};

//step2: create view
class StudentView
{
  public:
    void printStudentDetails(string studentName, string studentRollNo)
    {
        cout << "Student: " << endl;
        cout << "Name: " << studentName << endl;
        cout << "Roll No: " << studentRollNo << endl;
    }
};

//step3: Create Controller
class StudentController
{
  private:
    Student *model;
    StudentView *view;

  public:
    StudentController(Student *new_model, StudentView *new_view)
    {
        model = new_model;
        view = new_view;
    }

    void setStudentName(string name)
    {
        model->setName(name);
    }

    string getStudentName()
    {
        return model->getName();
    }

    void setStudentRollNo(string rollNo)
    {
        model->setRollNo(rollNo);
    }

    string getStudentRollNo()
    {
        return model->getRollNo();
    }

    void updateView()
    {
        view->printStudentDetails(model->getName(), model->getRollNo());
    }
};

Student *retriveStudentFromDatabase()
{
    Student *student = new Student();
    student->setName("Robert");
    student->setRollNo("10");
    return student;
}

//step3: verify output
int main()
{
    //fetch student record based on his roll no from the database
    Student *model = retriveStudentFromDatabase();

    //Create a view : to write student details on console
    StudentView *view = new StudentView();;

    StudentController *controller = new StudentController(model, view);

    controller->updateView();

    //update model data
    controller->setStudentName("John");

    controller->updateView();
    return 0;
}