#include <iostream>
using namespace std;


class Plus
{
  private:
    int arr[10];

  public:
    Plus(int initValue)
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = initValue;
        }
    }

    //print method
  public:
    void PrintArray()
    {
        for (int i = 0; i < 10; i++)
        {
            if(arr[i]<10)
            {
                cout<<" "<< arr[i] << " ";
            }
            else
            {
                cout << arr[i] << " ";
            }
            
        }
        cout<<endl;
    }

    //overload + operator
    Plus operator+(const Plus &AnotherObject)
    {
        Plus newArr(0);
        for (int i = 0; i < 10; i++)
        {
            newArr.arr[i] = this->arr[i] + AnotherObject.arr[i];
        }
        return newArr;
    }
};

int main()
{
    Plus FirstObject(4);
    Plus SecondObject(6);

    FirstObject.PrintArray();
    SecondObject.PrintArray();

    Plus DifferenceObject(0);

    DifferenceObject = FirstObject + SecondObject;
    DifferenceObject.PrintArray();
    return 0;
}



/*solutions
#include <iostream>
using namespace std ;

class Plus
{
private:
	int Array [10];
public:
	Plus (int InitValue) ;

	void PrintArray () ;
	Plus operator+  (Plus &AnotherObject) ;
};
Plus::Plus (int InitValue)
{
	for (int i=0;i<10; i++)
	{
		Array [i] = InitValue;
	}
}

void Plus::PrintArray ( )
{
	cout << endl ;

	for (int i=0;i<10; i++)
	{
		cout.width (3);
		cout << Array [i] ;
	}
	cout << endl ;
}

Plus  Plus::operator+ (Plus  &AnotherObject)
{
	Plus  DifferenceArray(0);
	for (int i=0;	i<10;	i++)
	{
		DifferenceArray.Array[i] = Array [i] + AnotherObject.Array[i] ;
	}
	return DifferenceArray ;
}

int main ( )
{
	Plus   FirstObject (4);
	Plus   SecondObject (6);
	FirstObject.PrintArray () ;
	SecondObject.PrintArray () ;
	Plus   DifferenceObject (0);
	DifferenceObject = FirstObject + SecondObject ;
	DifferenceObject.PrintArray() ;
	cout << "\n";
	return 0;
}*/