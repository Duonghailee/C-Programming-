#include <iostream>
#include <string>

using namespace std;

//State pattern
//step 1: Create an interface
class State
{
  public:
    virtual void doAction(class Context *context) = 0;
    virtual void toString() = 0;
};

//step2 : Create concrete classes implementing the same interface.
class StartState : public State
{
  public:
    void doAction(Context *new_context);

  public:
    void toString()
    {
        cout << "Start state" << endl;
    }
};
class StopState : public State
{
  public:
    void doAction(Context *new_context);

  public:
    void toString()
    {
        cout << "Stop state" << endl;
    }
};

//step 3: create Context class
class Context
{
  protected:
    State *state;

  public:
    Context()
    {
        state = NULL;
    }
    void setState(State *new_state)
    {
        state = new_state;
    }

  public:
    State *getState()
    {
        return state;
    }
};


//doAction function after Context class has been declared
void StartState::doAction(Context *new_context)
{
    cout << "Player is in start state" << endl;
    new_context->setState(new StartState());
}

void StopState::doAction(Context *new_context)
{
    cout << "Player is in stop state" << endl;
    new_context->setState(new StopState());
}

//verify output
int main()
{
    Context context;

    StartState startState;
    startState.doAction(&context);
    context.getState()->toString();

    StopState stopState;
    stopState.doAction(&context);
    context.getState()->toString();
    return 0;
}
