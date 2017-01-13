#include <iostream>
#include <string>
using namespace std;

class Player
{
  private:
    int dices[6] = {1, 2, 3, 4, 5, 6};

  public:
    int getRollNo()
    {
        int random = rand() % 6;
        return dices[random];
    }
};

class PlayerView
{
  public:
    void printDiceDetails(int point)
    {
        cout << "Dice: " << point << endl;
    }
};

//step3: Create Controller
class PlayerController
{
  private:
    Player *model;
    PlayerView *view;

  public:
    PlayerController(Player *new_model, PlayerView *new_view)
    {
        model = new_model;
        view = new_view;
    }

    void updateView()
    {
        view->printDiceDetails(model->getRollNo());
    }
};

//step3: verify output
int main()
{
    srand(time(NULL)); //set the seeds
    int times;
    int i = 0;
    cout << "How many times you want to throw a dice: ";
    cin >> times;
    cout << endl;
    while (i < times)
    {
        //fetch player record based on his roll no from the database
        Player *model = new Player();

        //Create a view : to write player details on console
        PlayerView *view = new PlayerView();

        PlayerController *controller = new PlayerController(model, view);

        controller->updateView();
        i++;
    }
    return 0;
}