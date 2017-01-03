#include <iostream>
#include <string>
using namespace std;

// your code here

class AskAndPrint
{
public:
  	void DoYourThing(char str[50]);
};

void AskAndPrint::DoYourThing(char str[50]){
	cout<<str;
	char stringToPrint[50];
	cin.get(stringToPrint, 50);
 	cout<<stringToPrint<<endl;
}

 
int main (void)
{  
   char text[] = "Write the text for printing:";
   AskAndPrint thing;
   thing.DoYourThing(text);
}