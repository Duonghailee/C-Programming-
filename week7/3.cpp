#include <iostream>  // std:cout
#include <algorithm> //std::find
using namespace std;

int main()
{
    int arr[] = {45, 2, 22, -17, 0, -30, 25, 55};
    std::sort(arr, arr + 8); //using sort as default comparison operator <
    int *p = &arr[0];        // base pointer
    //loop in array thourgh pointer to print value of array
    while (p < (arr + 8))
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}