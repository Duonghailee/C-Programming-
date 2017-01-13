#include <iostream>  // std:cout
#include <algorithm> //std::find
using namespace std;

int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int *baseptr = &arr[0]; //initial base offset
    int *p = std::find(arr, arr + 8, 33);
    if (p != arr + 8) // not equal to last iterator, found value!!
    {
        cout << "First object with value 33 found at offset " << (p - baseptr) << endl;
    }
    else
    {
        cout << "Object with value 33 not found in array" << endl;
    }
    return 0;
}