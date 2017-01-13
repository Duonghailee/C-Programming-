#include <iostream>
using namespace std;

// 2D implementation
class TwoD {
protected:
	int x;
	int y;

	// constructor begins
public:
	TwoD(int x_value, int y_value) {
		x = x_value;
		y = y_value;
	}

	// set and get methods
	void set_X(int x_value) {
		x = x_value;
	}
	void set_Y(int y_value) {
		y = y_value;
	}
	int get_X() {
		return x;
	}
	int get_Y() {
		return y;
	}

	// print results
	void print_info() {
		cout << "Coordinates for the 2d object are:" << endl << x << ", " << y
				<< endl;
	}
};
// ThreeD inheritance 
class ThreeD: public TwoD {
protected:
	// extra direction z
	int z;

public:
	ThreeD(int x_value, int y_value, int z_value) :
			TwoD(x_value, y_value) {
		z = z_value;
	}
	;

	// set and get methods
	void set_Z(int z_value) {
		z = z_value;
	}
	int getZ() {
		return z;
	}

	// print result
	void print_info() {
		cout << "Coordinates for the 3d object are:" << endl << x << ", " << y
				<< ", " << z << endl;
	}
};

int main() {
	TwoD D2(2, 3);
	ThreeD D3(1, 4, 5);
	D2.set_X(1); // test the setX function
	D3.set_Z(5); // test the testZ function
	D2.print_info();
	D3.print_info();
	return 0;
}
