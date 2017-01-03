#include <iostream>
using namespace std;

class AreaOfRectangle
{
    public:
    int x, y;
    int area()
    {
        return x*y;
    }
};

int main(){
    AreaOfRectangle rect;
    cout<< "Enter length of rectangle:";
    cin>>rect.x;
    cout<< "Enter breath of rectangle:";
    cin>>rect.y;
    cout<< "Area:"<< rect.area()<<endl;
    return 0;
}