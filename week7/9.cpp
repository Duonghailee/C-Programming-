#include <iostream> // std:cout
#include <deque>
using namespace std;

int main()
{
    deque<int> deq;
    deq.push_back(30);
    deq.push_back(40);
    deq.push_back(50);
    deq.push_front(20);
    deq.push_front(10);

    // change middle value to 33
    //erase the 3element and reinsert 33
    deq.erase(deq.begin() + 2);
    deq.insert(deq.begin() + 2, 33);

    //display elements
    std::deque<int>::iterator it;
    for (it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}