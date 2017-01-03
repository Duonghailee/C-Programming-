#include <iostream>
#include <string>
using namespace std;
class PrintClass{
    public:
        void print(char str[50]);
};
void PrintClass::print(char str[50]){
    cout<<str<<endl;
}
int main()
{
  char charstring[50];
  cout << "Input character string for printing:";
  cin.get(charstring, 50);
  PrintClass printer;
  printer.print(charstring);
}
//hihi,just a comment        
