#include <iostream> // std:cout
#include <list>
using namespace std;

int main()
{
    std::list<int> ilist;
    ilist.push_back(30);
    ilist.push_back(40);

    ilist.push_front(20);
    ilist.push_front(10);

    //print list
    std::list<int>::iterator it;
    for (it = std::begin(ilist); it != std::end(ilist); ++it)
    {
        std::cout << *it << " ";
    }
    cout << endl;
}