#include <iostream>
using namespace std;

class Member
{
  public:
    Member()
    {
    }
    //constructor definition
    Member(string newID, string newName, double bonusMoney)
    {
        cout << "constructor called" << endl;
        ID = newID;
        name = newName;
        bonus = bonusMoney;
    }
    Member(string newID, string newName)
    {
        cout << "constructor called" << endl;
        ID = newID;
        name = newName;
        bonus = 20.0;
    }
    //set ID method
    void setID(string newID)
    {
        ID = newID;
    }
    // set Name method
    void setName(string newName)
    {
        name = newName;
    }
    // set money method
    void setMoney(double money)
    {
        bonus = money;
    }
    // get info methods
    string getID()
    {
        return ID;
    }
    string getName()
    {
        return name;
    }
    double getBonus()
    {
        return bonus;
    }

    //increase bonus money method
    void increase_bonus_money(double increment)
    {
        bonus += increment;
    }

    // print info method
    void printInfo()
    {
        cout << "member name: " << name << " ,ID: " << ID << ", bonus money: " << bonus << endl;
    }

  private:
    string ID;
    string name;
    double bonus;
};

int main()
{
    Member member1;
    Member member2;

    //ex2
    member1.setID("150150");
    member1.setName("Alibaba");
    member1.setMoney(0);

    member2.setID("150051");
    member2.setName("Geogre");
    member2.setMoney(0);

    member1.printInfo();
    member2.printInfo();
    cout << "ex3" << endl;
    // ex3
    member1.increase_bonus_money(3);
    member2.increase_bonus_money(5);
    member1.printInfo();
    member2.printInfo();
    cout << "ex4" << endl;
    //ex4
    Member memberA("Alibaba", "1504111", 50);
    memberA.printInfo();
    cout << "ex5" << endl;
    //ex5
    Member memberB("Geogre Washington", "140111");
    memberB.printInfo();
    return 0;
}
