#include <iostream>
#include <string>
using namespace std;

// your code
class Dog
{
public:
    int age;
    string name, race, voice;
    
    Dog(int age, string name, string race, string voice);
    void PrintInformation();
    string Bark();      
};

Dog::Dog(int newAge, string newName, string newRace, string newVoice )
{
    age = newAge;
    name = newName;
    race = newRace;
    voice = newVoice;
}

void Dog::PrintInformation()
{
    cout<< "Name: "<< name <<"\nAge: "<<age<<"\nRace: "<<race<<endl;
}
string Dog::Bark()
{
    return voice;
}

int main()
{
  Dog buffy(2, "Buffy", "Bulldog", "Hau!!!");
  buffy.PrintInformation();
  cout << "Dog says: " << buffy.Bark();
} 