#include <iostream> // std:cout
#include <list>
#include <ctype.h>
#include <string>
using namespace std;

//compare in alphabet order
bool alphabet_order(const char &first, const char &second)
{
    return first < second;
}

int main()
{
    std::list<char> clist;

    cout << "Enter character one at time, space is ending: ";
    char c;
    do
    {
        c = cin.get();
        if (c != '\n' && c != ' ') //ignore "enter" character
        {
            clist.push_back(c);
        }

    } while (c != ' ');

    //sort list
    clist.sort(alphabet_order);
    //print list in alphabet order
    cout<<"List in alphabet order: ";
    std::list<char>::iterator it;
    for (it = std::begin(clist); it != std::end(clist); ++it)
    {
        std::cout << *it << " ";
    }
    cout << endl;

    //print reserve list
    cout<<"List in descending alphabet order: ";
    clist.reverse();
    for (it = std::begin(clist); it != std::end(clist); ++it)
    {
        std::cout << *it << " ";
    }
    cout << endl;

    return 0;
}