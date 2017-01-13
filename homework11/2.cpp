#include <iostream>
#include <string>
using namespace std;

class Player
{
  private:
    string name;
    int dices[6] = {1, 2, 3, 4, 5, 6}; 
    int point;

  public:
    void setName(string pName)
    {
        name = pName;
    }
    void setRollNo()
    {
        int random = rand() % 6;
        point = dices[random];
    }
    int getRollNo()
    {
        return point;
    }
    string getPlayerName()
    {
        return name;
    }
};

class PlayerView
{
  public:
    void printDiceDetails(string playerName, int point)
    {
        cout << "Player:  " << playerName << endl;
        cout << "   Point No: " << point << endl;
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

    void setPlayerName(string name)
    {
        model->setName(name);
    }

    string getPlayerName()
    {
        return model->getPlayerName();
    }

    void roll_a_dice()
    {
        model->setRollNo();
    }

    int getRollNo()
    {
        return model->getRollNo();
    }

    void updateView()
    {
        view->printDiceDetails(model->getPlayerName(), model->getRollNo());
    }
};

Player *retrivePlayerFromDatabase()
{
    string name;
    Player *player = new Player();
    cout << "Enter player name: ";
    cin >> name;
    player->setName(name);
    player->setRollNo();

    return player;
}

//step3: verify output
int main()
{
    srand(time(NULL)); //set the seeds
    bool isContinue = true;
    char ans; //read y/n from user if he/she wants to continue
    int winCount = 0, lostCount = 0, drawCount = 0;

    cout << "-----------Welcome to Roll a dice game-------------- \n";
    while (isContinue)
    {
        //fetch player record based on his roll no from the database
        Player *model = retrivePlayerFromDatabase();

        //Create a view : to write player details on console
        PlayerView *view = new PlayerView();

        PlayerController *controller = new PlayerController(model, view);

        controller->updateView();
        int userPoint = controller->getRollNo();

        //update model data
        controller->setPlayerName("machine");
        controller->roll_a_dice();
        int machinePoint = controller->getRollNo();
        controller->updateView();
        if (userPoint > machinePoint)
        {
            cout << " Congrat! User win " << endl;
            winCount++;
        }
        else if (userPoint < machinePoint)
        {
            cout << "Oh, you lost, good luck nex time " << endl;
            lostCount++;
        }
        else
        {
            cout << "Draw game " << endl;
            drawCount++;
        }
        cout << "Do you want to replay ? (y/n) ";
        cin >> ans;
        if (ans == 'n')
        {
            cout << "You have won: " << winCount << " match(es) " << endl;
            cout << "You have lost: " << lostCount << " match(es) " << endl;
            cout << "You have " << drawCount << " draw match(es) " << endl;
            cout << "Thank for playing, hope you feel happy <3333333" << endl;
            isContinue = false;
        }
        else if (ans == 'y')
        {
            cout << " I glad to see you again, brave man" << endl;
            continue;
        }
        else
        {
            do
            {
                cout << "Please enter only y,n " << endl;
                cin >> ans;

            } while (ans != 'y' && ans != 'n');
            if (ans == 'n')
            {
                cout << "You have won: " << winCount << " match(es) " << endl;
                cout << "You have lost: " << lostCount << " match(es) " << endl;
                cout << "You have " << drawCount << " draw match(es) " << endl;
                cout << "Thank for playing, hope you feel happy <3333333" << endl;
                isContinue = false;
            }
            else if (ans == 'y')
            {

                {
                    cout << " I glad to see you again, brave man" << endl;
                }
            }
        }
    }
    return 0;
}