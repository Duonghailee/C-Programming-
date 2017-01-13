#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char c;
    ifstream fromfile("A.txt");
    ofstream tofile("B.txt");
    if (fromfile.is_open())
    {
        while (fromfile.get(c))
        {
            tofile << c;
        }
        tofile.close();
        fromfile.close();
    }
    cout << "Copying successfully" << endl;
    return 0;
}