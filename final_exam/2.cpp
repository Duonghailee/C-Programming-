#include <iostream>
#include <fstream>
#include <vector> //push_back 
#include <algorithm> //std::count, search

using namespace std;
int main(int argc, char *argv[])
{
    std::fstream myfile("A.txt", std::ios_base::in);
    vector<int> v;

    int a;
    int num = 0;
    int min;
    int max;
    int min_count;
    int max_count;
    while (myfile >> a)
    {
        v.push_back(a);
        num++;
    }

    //search the smallest, the largest
    auto min_pointer = min_element(begin(v), end(v));
    auto max_pointer = max_element(begin(v), end(v));

    //count for smallest and the larget
    min_count = count(begin(v), end(v), *min_pointer);
    max_count = count(begin(v), end(v), *max_pointer);

    //print results
    cout << "In file are " << num << " integers." << endl;
    cout << "Minimum number " << *min_pointer << " exists " << min_count << " times" << endl;
    cout << "Maximum number " << *max_pointer << " exists " << max_count << " times" << endl;

    return 0;
}
