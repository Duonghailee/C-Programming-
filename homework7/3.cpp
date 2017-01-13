#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream tofile;
    tofile.open("test.txt");
    std::string input;
    while (true)
    {
        cout << "Enter a string (CR to quit): " << endl;
        getline(cin, input);
        if (input == "")
        {
            return 0;
        }
        else
        {
            tofile << input << endl;
        }
    }
}