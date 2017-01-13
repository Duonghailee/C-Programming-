#include <iostream>
#include <array>
using namespace std;

//SORTING ARRAY

template <class T>

void bubble_sort(T arr[], int n)
{
    int i, j;
    // T temp for swap
    T temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//PRINTING ARRAY
template <class T>

void print_arr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int iarray[7] = {7, 5, 4, 3, 9, 8, 6};
    //get size of array
    int isize = sizeof(iarray) / sizeof(*iarray);
    
    double darray[5] = {4.3, 2.5, -0.9, 100.2, 3.0};
    int dsize = sizeof(darray) / sizeof(*darray);

    //print array
    cout << "Here is unsorted integer array: ";
    print_arr<int>(iarray, isize);

    cout << "Here is unsorted double array: ";
    print_arr<double>(darray, dsize);

    //sorting
    cout << "Here is sorted integer array: ";
    bubble_sort<int>(iarray, isize);
    print_arr<int>(iarray, isize);

    cout << "Here is sorted double array: ";
    bubble_sort<double>(darray, dsize);
    print_arr<double>(darray, dsize);
    cout<<endl<<endl;

    return 0;
}
