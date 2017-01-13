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
    ComputerPart *parts[3];

  public:
    void accept(ComputerPartVisitor *computerPartVisitor);
    void setElement(ComputerPart *set_parts[3])
    {
        parts[0] = set_parts[0];
        parts[1] = set_parts[1];
        parts[2] = set_parts[2];
    }
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

//function inside each class is now implemented
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
    for (int i = 0; i < 3; ++i)
    {
        Computer::parts[i]->accept(computerPartVisitor);
    }
    computerPartVisitor->visit(this);
}

//step5: verify output
int main()
{
    ComputerPartDisplayVisitor *computerPartDisplayVisitor = new ComputerPartDisplayVisitor();
    ComputerPart *parts[3] = {new Mouse(), new Keyboard(), new Monitor()};
    Computer *computer = new Computer();
    computer->setElement(parts);
    computer->accept(computerPartDisplayVisitor);
    return 0;
}
