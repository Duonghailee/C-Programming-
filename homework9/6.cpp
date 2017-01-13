#include <iostream>
#include <vector>
using namespace std;

/* Builde pattern */
// step 1 Create an interface Item representing food item and packing.

class Packing
{
  public:
    virtual std::string pack() = 0;
};

class Item
{
  public:
    virtual std::string name() = 0;
    virtual Packing *packing() = 0;
    virtual float price() = 0;
};

//step 2: Create concrete classes implementing the Packing interface.
class Wrapper : public Packing
{
  public:
    std::string pack()
    {
        return "Wrapper";
    }
};

class Bottle : public Packing
{
  public:
    std::string pack()
    {
        return "Bottle";
    }
    std::string name()
    {
    }
};

//step 3: Create abstract classes implementing the item interface providing default functionalities.
class Burger : public Item
{
  public:
    Packing *packing()
    {
        return new Wrapper();
    }

    float price()
    {
    }
    std::string name()
    {
    }
};

class ColdDrink : public Item
{
  public:
    Packing *packing()
    {
        return new Bottle();
    }

    float price()
    {
    }
    std::string name()
    {
    }
};

//step 4: Create concrete classes extending Burger and ColdDrink classes
class VegBurger : public Burger
{
  public:
    float price()
    {
        return 25.0;
    }
    std::string name()
    {
        return "Veg Burger";
    }
};

class ChickenBurger : public Burger
{
  public:
    float price()
    {
        return 50.5;
    }
    std::string name()
    {
        return "Chicken Burger";
    }
};

class Coke : public ColdDrink
{
  public:
    float price()
    {
        return 30.0;
    }

    std::string name()
    {
        return "Coke";
    }
};

class Pepsi : public ColdDrink
{
  public:
    float price()
    {
        return 35.0;
    }

    std::string name()
    {
        return "Pepsi";
    }
};

//step 5: Create a Meal class having Item objects defined above.
class Meal
{
  private:
    vector<Item *> meal;

  public:
    void addItem(Item *item)
    {

        meal.push_back(item);
    }

    float getCost()

    {
        // vector<Item*>::iterator it;
        float cost = 0.0;
        for (int i = 0; i < meal.size(); i++)
        {
            cost += meal[i]->price();
        }
        return cost;
    }

    void showItems()
    {
        for (int i = 0; i < meal.size(); i++)
        {
            cout << "Item: " << meal[i]->name();
            cout << ", Packing: " << meal[i]->packing()->pack();
            cout << ", Price: " << meal[i]->price();
            cout << endl;
        }
    }
};

//step 6: Create a MealBuilder class, the actual builder class responsible to create Meal objects.
class MealBuilder
{
  public:
    Meal prepareVegMeal()
    {
        Meal meal;
        Coke *coke = new Coke;
        VegBurger *vegBurger = new VegBurger;
        meal.addItem(coke);
        meal.addItem(vegBurger);
        return meal;
    }

    Meal prepareNonVegMeal()
    {
        Meal meal;
        Pepsi *pepsi = new Pepsi;
        ChickenBurger *chickenBurger = new ChickenBurger;
        meal.addItem(pepsi);
        meal.addItem(chickenBurger);
        return meal;
    }
};

//step 7 : verify results
int main()
{
    MealBuilder mealBuilder;

    Meal vegMeal = mealBuilder.prepareVegMeal();
    cout << "Veg Meal" << endl;
    vegMeal.showItems();
    cout << "Total Cost: " << vegMeal.getCost() << endl;

    Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
    cout << "\nNon-Veg Meal" << endl;
    nonVegMeal.showItems();
    cout << "Total Cost: " << nonVegMeal.getCost() << endl;
    return 0;
}
