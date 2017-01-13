#include <iostream>
using namespace std;

//Template Pattern
//step 1: Create an abstract class with a template method being final.
class Game
{
  public:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

  public:
    void play()
    {
        initialize();
        startPlay();
        endPlay();
    }
};

//step2: Create concrete classes extending the above class.
//Cricket class
class Cricket : public Game
{
  public:
    void endPlay()
    {
        cout << "Cricket Game Finished!" << endl;
    }

    void initialize()
    {
        cout << "Cricket Game Initialized! Start playing." << endl;
    }

    void startPlay()
    {
        cout << "Cricket Game Started. Enjoy the game!" << endl;
    }
};

//Football
class Football : public Game
{
  public:
    void endPlay()
    {
        cout << "Football Game Finished!" << endl;
    }

    void initialize()
    {
        cout << "Football Game Initialized! Start playing." << endl;
    }

    void startPlay()
    {
        cout << "Football Game Started. Enjoy the game!" << endl;
    }
};

//step3: verify output
int main()
{
    Game *game = new Cricket();
    game->play();

    cout << endl;

    game = new Football();
    game->play();
    return 0;
}
