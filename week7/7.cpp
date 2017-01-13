#include <iostream> // std:cout
#include <vector>
using namespace std;

//print vector function
void print_vector(std::vector<int> v)
{
    std::vector<int>::iterator it;
    for (it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {100, 110, 120, 130};
    //copy arr into vector
    std::vector<int> v(arr, arr + 4);

    //initial iterator 
    std::vector<int>::iterator it;
    //print before insertion:
    cout << "Before insertion: ";
    print_vector(v);

    // push 115 in the middle of array
    it = v.begin();
    v.insert(it + 2, 115);
    //print after insertion:
    cout << "After insertion: ";
    print_vector(v);

    //erase the second element
    it = v.begin();
    v.erase(it + 2);
    //print after erasure;
    cout << "After erasure:   ";
    print_vector(v);
}

/* solution
// vectins.cpp
// demonstrates insert(), erase()
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int j;
	int arr[] = { 100, 110, 120, 130 };  //an array of ints
	vector<int> v(arr, arr+4);       // initialize vector to array

	cout << "\nBefore insertion: ";
   	for(j=0; j<v.size(); j++)    // display all elements
		cout << v[j] << ' ';

	v.insert( v.begin()+2, 115);     // insert 115 at element 2

   	cout << "\nAfter insertion:  ";
   	for(j=0; j<v.size(); j++)        // display all elements
		cout << v[j] << ' ';

   	v.erase( v.begin()+2 );          // erase element 2

   	cout << "\nAfter erasure:    ";
   	for(j=0; j<v.size(); j++)        // display all elements
		cout << v[j] << ' ';
   	cout << endl;
   	return 0;
}
*/