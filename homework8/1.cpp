#include <iostream>  // std:cout
#include <string> // std::string::length
#include <vector> //std::vector::pop_back, push_back, back
using namespace std;

int main()
{

    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "\nOriginal string: " << str << endl;

    //copy string into vector using push_back
    std::vector<char>::iterator it;
    std::vector<char> v;
    for (int i = 0; i < str.length(); ++i)
    {
        v.push_back(str.at(i));
    }

    // reverse string
    cout << "Reverse string: ";
    for (int i = v.size(); i >= 0; --i)
    {
        cout << v[i];
    }
    cout << endl;

    //remove space
    for (it = v.begin(); it < v.end(); it++)
    {
        if (' ' == *it) //found space
        {
            v.erase(it);
        }
    }

    /*test remove space
    cout << "String is now \"space\" free: ";
    for (it = v.begin(); it < v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;*/


    //check palidrome
    bool isPalidrome = true;
    for (it = v.begin(); isPalidrome && v.size() != 0; ++it)
    {
        isPalidrome = *it == v.back();
        v.pop_back();
    }

    if (isPalidrome)
    {
        cout << "String is palindrome";
    }
    else
    {
        cout << "\nString is not palindrome";
    }

    cout << endl;
    return 0;
}
