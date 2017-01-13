#include <iostream> // std:cout
#include <list>
#include <ctime>
using namespace std;

bool compare(const int &n1, const int &n2)
{
    return n1 < n2;
}

int main()
{
    std::list<int> random_list;
    std::list<int>::iterator it;
    int i = 0;
    int random_num;
    //generating 10 int numbers

    while (i < 10)
    {
        random_num = std::rand() % 30000; //range from 1 - 29999
        random_list.push_back(random_num);
        i++;
    }
    //print list before sort
    cout << "Original list: ";
    for (it = std::begin(random_list); it != std::end(random_list); ++it)
    {
        std::cout << *it << " ";
    }
    cout << endl;

    //print sort list
    cout << endl;
    cout << "Sorted contents: ";
    random_list.sort(compare);
    for (it = std::begin(random_list); it != std::end(random_list); ++it)
    {
        std::cout << *it << " ";
    }
    cout << endl;
}
