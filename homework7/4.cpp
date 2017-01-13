#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// person class
class person
{
  public:
    string forename, surname;
    int age;
    void set_info()
    {
        cout << "Input: " << endl;
        cout << "Enter forename: ";
        cin >> forename;
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter age: ";
        cin >> age;
    }
    void display()
    {
        cout << "Output: " << endl;
        cout << "Forename: " << forename << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    //opening file person.dat
    fstream fs("person.dat", ios::out | ios::binary);

    //write object to file as binary format
    person user;
    user.set_info();
    fs.write((char *)(&user), sizeof(user));
    fs.close();

    // reading from file person.dat
    person temp; //create a temp object to store data reading from file
    fs.open("person.dat");
    while (fs.read((char *)&temp, sizeof(temp)))
    {
        temp.display();
    }
    fs.close();
    return 0;
}