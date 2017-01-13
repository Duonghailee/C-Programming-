#include <iostream>
#include <array>
using namespace std;

template <class T>
void search(T *ptr, T value, int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (value == *(ptr + i))
        {
            index = i;
        }
    }
    cout<<value<<" in chrArray: index="<<index<<endl;
}

int main()
{
    int *ptr;
    int test_arr[] = {1, 2, 3, 4, 5, 6};
    ptr = test_arr; // pointer to the first element of array
    search<int>(ptr, 3, 6);
    return 0;
}