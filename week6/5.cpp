#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char fname[15], lname[20], c, phone[15];
    //opening file and write number of lines
    ofstream tempfile;
    tempfile.open("phone.txt", ios::app);
    //asking information
    cout << "Program saves your forename, surname and phone into the file." << endl;
    cout << "Enter your forename (first name): ";
    cin >> fname;
    cout << "Enter your surname (last name): ";
    cin >> lname;
    cout << "Enter your phone number: ";
    cin >> phone;

    //writing to temp file
    tempfile << fname << " " << lname << " " << phone << '\n';
    tempfile.close();
    cout << "\nWriting to a file managed!." << endl;

    // the idea is counting lines of temp file and then adding lines,
    // data to the destination file
    ifstream fromfile; // reading from temp file
    ofstream tofile;   // writing to destination file
    fromfile.open("phone.txt");
    tofile.open("phones.txt");


    // count lines
    int lines = 0;
    std::string line;
    while (std::getline(fromfile, line))
    {
        ++lines;
    }


    //finish count and write lines
    //clear eof flags
    fromfile.clear();
    fromfile.seekg(0, ios::beg);

    //this is where we update the number of lines
    tofile << lines << endl;
    while (std::getline(fromfile, line))
    {
        tofile << line << '\n';
    }

    return 0;
}