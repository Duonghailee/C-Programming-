#include <iostream>  // std:cout
#include <algorithm> //std::search
using namespace std;

int main()
{
    int source[] = {11, 44, 33, 11, 22, 33, 11, 22, 44};
    int pattern[] = {11,22,33};
    int *baseptr = &source[0]; //initial base offset
    int *p = std::search(source,source+9,pattern,pattern+3); //search as default  of stl
    if (p != source + 9) // not equal to last iterator, found !!!
    {
        cout << "Match at  " << (p - baseptr) << endl;
    }
    else
    {
        cout << "There is no first occurence of pattern in source" << endl;
    }
    return 0;
}