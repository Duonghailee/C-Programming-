#include <iostream> // std:cout
#include <string>   // std::string::length
#include <vector>
#include <fstream>
#include <algorithm> //std::count, std::sort
using namespace std;

//count different scores function
int count_score(int score, std::vector<int> v)
{
    int count = 0;
    count = std::count(v.begin(), v.end(), score);
    return count;
}

//print stars base on grade function
void print_star_byscore(int score, int count_of_score)
{
    cout << score << ": ";
    for (int i = 0; i < count_of_score; ++i)
    {
        cout << "*";
    }
    cout << endl;
}

int main()
{
    //open file score.txt for reading
    ifstream readfile("scores.txt");

    //create a vector to store read value
    vector<int> v;
    vector<int>::iterator it;

    //temp value to store is_integer
    int score;
    if (readfile.is_open())
    {
        while (readfile >> score)
        {
            v.push_back(score);
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    //test vector which stores score
    for (it = v.begin(); it < v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //sort vector
    sort(v.begin(), v.end());

    //count score in vector
    int n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    n0 = count_score(0, v);
    n1 = count_score(1, v);
    n2 = count_score(2, v);
    n3 = count_score(3, v);
    n4 = count_score(4, v);
    n5 = count_score(5, v);

    //print result:
    print_star_byscore(0, n0);
    print_star_byscore(1, n1);
    print_star_byscore(2, n2);
    print_star_byscore(3, n3);
    print_star_byscore(4, n4);
    print_star_byscore(5, n5);

    return 0;
}