#include <iostream>
using namespace std;

//Visitor Pattern

//step1: Define an interface to represent element.
//CompuerPart interface

class ComputerPart
{
  public:
    virtual void accept(class ComputerPartVisitor *computerPartVisitor) = 0;
};

//step2: Create concrete classes extending the above class.
//Keyboard class

class Keyboard : public ComputerPart
{
  public:
    void accept(ComputerPartVisitor *computerPartVisitor);
};

//Monitor class
class Monitor : public ComputerPart
{

  public:
    void accept(ComputerPartVisitor *computerPartVisitor);
};

//Mouse class
class Mouse : public ComputerPart
{
  public:
    void accept(ComputerPartVisitor *computerPartVisitor);
};

//Computer class
class Computer : public ComputerPart
{
    ComputerPart *parts[3] = {new Mouse(), new Keyboard(), new Monitor()};

  public:
    void accept(ComputerPartVisitor *computerPartVisitor);
};

//step3: Define an interface to represent visitor.
class ComputerPartVisitor
{
  public:
    virtual void visit(Computer *computer) = 0;
    virtual void visit(Mouse *mouse) = 0;
    virtual void visit(Keyboard *keyboard) = 0;
    virtual void visit(Monitor *monitor) = 0;
};

//step 4: Create concrete visitor implementing the above class.
class ComputerPartDisplayVisitor : public ComputerPartVisitor
{
  public:
    /*virtual*/ void visit(Computer *computer)
    {
        cout << "Displaying Computer." << endl;
    }

    /*virtual*/ void visit(Mouse *mouse)
    {
        cout << "Displaying Mouse." << endl;
    }

    /*virtual*/ void visit(Keyboard *keyboard)
    {
        cout << "Displaying Keyboard." << endl;
    }

    /*virtual*/ void visit(Monitor *monitor)
    {
        cout << "Displaying Monitor." << endl;
    }
};

void Keyboard::accept(ComputerPartVisitor *computerPartVisitor)
{
    computerPartVisitor->visit(this);
}

void Mouse::accept(ComputerPartVisitor *computerPartVisitor)
{
    computerPartVisitor->visit(this);
}

void Monitor::accept(ComputerPartVisitor *computerPartVisitor)
{
    computerPartVisitor->visit(this);
}

void Computer::accept(ComputerPartVisitor *computerPartVisitor)
{
    int size = sizeof(parts) / sizeof(parts[0]);
    for (int i = 0; i < size; i++)
    {
        parts[i]->accept(computerPartVisitor);
    }
    computerPartVisitor->visit(this);
}

//step5: verify output
int main()
{
    Computer *computer = new Computer();
    ComputerPartDisplayVisitor *computerPartDisplayVisitor = new ComputerPartDisplayVisitor();
    computer->accept(computerPartDisplayVisitor);

    return 0;
}
