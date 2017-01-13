#include <iostream>  
#include <algorithm> //std::count
using namespace std;

int main()
{
    int arr[] = {33, 22, 33, 44, 33, 55, 66, 77};
    int count = std::count(arr, arr + 8, 33);
    cout << "There are " << count << " 33's in arr." << endl;
    return 0;
}