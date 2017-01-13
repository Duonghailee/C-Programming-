#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char fname[15], lname[20], to_file[12];

    //asking information
    cout << "Program saves your forename and surename into the file." << endl;
    cout << "Enter your forename (first name): ";
    cin >> fname;
    cout << "Enter your surname (last name): ";
    cin >> lname;
    cout << "Enter file name: ";
    cin >> to_file;

    //writing to file
    ofstream myfile;
    myfile.open(to_file);
    myfile << fname << " " << lname << endl;
    myfile.close();
    cout << "\nSaving succeed!" << endl;
    return 0;
}