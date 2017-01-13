#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //convert decimal to binary
using namespace std;

//ref for convertion between dec, binary, oct and hexa
// http://stackoverflow.com/questions/28918861/is-there-a-pre-defined-built-in-function-to-convert-a-number-to-its-binary-forma

//Observer pattern
//step 1: create core class Subject
class Subject
{
  private:
    vector<class Observer *> observers;
    int state;

  public:
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    void setState(int new_state)
    {
        state = new_state;
        notifyAllObservers(); //update infor every time state is set
    }

    int getState()
    {
        return state;
    }

    void notifyAllObservers();
};

//step2: create Observer class
class Observer
{
  protected:
    Subject *subject;

  public:
    Observer(Subject *new_subject)
    {
        subject = new_subject;
        subject->attach(this);
    }
    virtual void update() = 0;

  protected:
    Subject *getSubject()
    {
        return subject;
    }
};

//notifyAllObservers function after declare inner class Observer
void Subject::notifyAllObservers()
{
    for (int i = 0; i < observers.size(); ++i)
    {
        observers[i]->update();
    }
}

//step 3: Create concrete observer classes
//Binary observer
class BinaryObserver : public Observer
{
  public:
    BinaryObserver(Subject *new_subject) : Observer(new_subject)
    {
    }
    void update()
    {
        int num = getSubject()->getState();
        string binary = bitset<4>(num).to_string();
        cout << "Binary String: " << binary << endl;
    }
};

// OctalObserver
class OctalObserver : public Observer
{
  public:
    OctalObserver(Subject *new_subject) : Observer(new_subject)
    {
    }
    void update()
    {
        int num = getSubject()->getState();
        char toOct[sizeof(int) * (unsigned int)(8.0f / 3.0f) + 2];
        //  char toHex[sizeof(int) * 8 / 4 + 1];
        sprintf(toOct, "%o", num);
        cout << "Octal String: " << toOct << endl;
    }
};

//HexaObserver
class HexaObserver : public Observer
{
  public:
    HexaObserver(Subject *new_subject) : Observer(new_subject)
    {
    }
    void update()
    {
        int num = getSubject()->getState();
        //char toOct[sizeof(int) * (unsigned int)(8.0f / 3.0f) + 2];
        char toHex[sizeof(int) * 8 / 4 + 1];
        sprintf(toHex, "%x", num);
        cout << "Hexa String: " << toHex << endl;
    }
};

//step 4: verify  output
int main()
{
    Subject subject;
    BinaryObserver binary(&subject);
    OctalObserver octal(&subject);
    HexaObserver hexa(&subject);
    cout << "First state change: 15" << endl;
    subject.setState(15);
    cout << "First state change: 10" << endl;
    subject.setState(10);
    return 0;
}
