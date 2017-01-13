#include <iostream>
using namespace std;

//base class
class Item
{
  protected:
    char code[20];
    char name[50];
    int cost;
    int num_on_hand;

  public:
    void getProduct()
    {
        cout << "Product code: ";
        cin >> code;
        cout << "Product name: ";
        cin >> name;
        cout << "Cost price: ";
        cin >> cost;
        cout << "Quantity on hand: ";
        cin >> num_on_hand;
    }
    void Productdis()
    {
        cout << "Product code: " << code << endl;
        cout << "product name: " << name << endl;
        cout << "Cost price: " << cost << endl;
        cout << "Quantity on hand; " << num_on_hand << endl;
    }
};

// derived class

class Sell : public Item
{
  protected:
    int selling_price;

  public:
    void getval(int set_price)
    {
        selling_price = set_price;
    }
    void showsp()
    {
        cout << "Selling price: " << selling_price << endl;
    }
};

// class discount
class discount
{
  protected:
    int discount_amount;

  public:
    void getdis(int set_discount)
    {

        discount_amount = set_discount;
    }
};

// derived class Bill
class Bill : public Sell, public discount
{
  protected:
    int num_bought;
    int total_price;

  public:
    void calprice(int num_purchase)
    {

        num_bought = num_purchase;
        total_price = num_bought * selling_price - discount_amount;
    }

    void showbill()
    {
        showsp();
        cout << "quantity to be purchased: " << num_bought << endl;
        cout << "discount: " << discount_amount << endl;
        cout << "total price: " << total_price << endl;
    }
};

int main()
{
    Bill bill;
    bill.getProduct();
    bill.getval(30000);
    bill.getdis(2000);
    bill.calprice(2);
    cout<<"----------------"<<endl;
    bill.Productdis();
    bill.showbill();
    return 0;
}
