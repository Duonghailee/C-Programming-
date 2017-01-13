#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    std::string fname, lname;

    // asking for data
    cout << "Give forname: ";
    getline(cin, fname);
    cout << "Give surname: ";
    getline(cin, lname);

    // reading file
    ifstream readfile;
    ofstream temp;
    std::string line;

    readfile.open("phone.txt");
    temp.open("phone2.txt");
    bool found = false;

    //continue till eof after storing the first line into line
    while (!readfile.eof())
    {
        getline(readfile, line);
        if ((line.find(fname) != std::string::npos) && (line.find(lname) != std::string::npos))
        {
            found = true;
        }
        else
        {
            temp << line << endl; // insert line which does not match search string into temp file
        }
    }
    if (found)
    {
        cout << "Information has been removed from the file." << endl;
        int remove = std::remove("phone.txt");          // delete old file
        int i = std::rename("phone2.txt", "phone.txt"); // rename temp to new file
    }
    else
    {
        cout << "Person's information can't be found." << endl;
    }

    return 0;
}