#include <iostream>
using namespace std;

class ThreeD
{
  private:
    int x, y, z;

  public:
    ThreeD()
    {
    }

    // 3 parameter constructor
    ThreeD(int x0, int y0, int z0)
    {
        x = x0;
        y = y0;
        z = z0;
    }

    //Overload opeartor ++
    ThreeD operator++()
    {
        ThreeD T(x, y, z);
        ++x;
        ++y;
        ++z;
        return T;
    }

    //Overload opeartor --
    ThreeD operator--()
    {
        ThreeD T(x, y, z);
        --x;
        --y;
        --z;
        return T;
    }

    // show method
    void show()
    {
        cout << x << ", " << y << ", " << z << endl;
    }
};

int main()
{
    ThreeD a(1, 2, 3);
    cout << "Original value of a: ";
    a.show();

    ++a;
    cout << "Value after ++a : ";
    a.show();

    --a;
    cout << "Value after --a : ";
    a.show();

    return 0;
}

/* solution
// Overload the ++ unary operator.

#include <iostream>
using namespace std;

class ThreeD {
	int x, y, z; // 3-D coordinates
public:
	ThreeD() { x = y = z = 0; }
	ThreeD(int i, int j, int k) {x = i; y = j; z = k; }
	
	ThreeD operator++(); // prefix version of ++
	ThreeD operator--(); // prefix version of --
	
	void show() ;
} ;

// Overload the prefix version of ++.
ThreeD ThreeD:: operator++ () // Overload ++ for ThreeD.
{
	x++; 		   // increment x, y and z	
	y++;			
	z++;			
	return *this; // Return the incremented object.
}

// Overload the prefix version of ++.
ThreeD ThreeD:: operator-- () // Overload ++ for ThreeD.
{
	x--; 		   // increment x, y and z	
	y--;			
	z--;			
	return *this; // Return the decremented object.
}
// Show X, Y, Z coordinates.
void ThreeD::show()
{
	cout << x << ", ";
	cout << y << ", ";
	cout << z << "\n";
}

int main()
{
	ThreeD a(1, 2, 3);

	cout << "Original value of a: "; 
	a.show();
	
	++a; // increment a
	cout << "Value after ++a: ";
	a.show();
	
	--a; // deccrement a
	cout << "Value after --a: ";
	a.show();
	
	return 0;
}
*/