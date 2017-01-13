#include <iostream>
using namespace std;
class add
{
  public:
    // case 2 int
    add(int a, int b)
    {
        cout << "Result: " << (a + b) << endl;
    }

    // case int and double
    add(int a, double d)
    {
        cout << "Result: " << (a + d) << endl;
    }

    // case 3 int
    add(int a, int b, int c)
    {
        cout << "Result: " << (a + b + c) << endl;
    }

    // case d,e,f
    add(double d, double e, double f)
    {
        cout << "Result: " << (d + e + f) << endl;
    }

    // case a,e,b
    add(int a, double e, int b)
    {
        cout << "Result: " << (a + e + b) << endl;
    }
};
int main()
{
    int a = 1, b = 2, c = 3;
    double d = 1.1;
    add(a, b);
    add(a, d);
    add(a, b, c);
    return 0;
}

/* SOLUTION 
#include <iostream>
using namespace std;

void add(int i, int j);
void add(int i, double j);
void add(int i, int j, int k);

int main(void)
{
   int    A = 1, B = 2, C = 3;
   double D = 1.1;

   add(A, B); //  1 + 2 => add prints 3
   add(A, D); //  1 + 1.1 => add prints 2.1
   add(A, B, C); // 1 + 2 + 3 => add prints 6
}

void add(int i, int j)
{
	cout << "Result: " << i + j << endl;
}
void add(int i, double j)
{
	cout << "Result: " << i + j << endl;
}
void add(int i, int j, int k)
{
	cout << "Result: " << i + j + k << endl;
}
*/