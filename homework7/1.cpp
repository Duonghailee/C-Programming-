#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream readfile;
    std::string line;
    readfile.open("phone.txt");
    //skip reading the first line (number) by getline
    getline(readfile, line);

    //continue till eof after storing the first line into line
    while (!readfile.eof())
    {
        getline(readfile, line);
        cout << line << endl;
    }
    return 0;
}