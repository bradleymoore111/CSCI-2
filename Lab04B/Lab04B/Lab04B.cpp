#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main() {
	cout << setprecision(3) << "Example ComplexNumber Operator Overloading." << endl;

	ComplexNumber a; // 0i + 0i
	ComplexNumber b(1, 1); // 1 + i
	ComplexNumber c(2, 4); // 2 + 4i

	ComplexNumber d = a + b; // Should be 1 + i
	ComplexNumber e = c - b; // Should be 1 + 3i

	ComplexNumber f = c * e; // Should be -10 + 10i
	ComplexNumber g = c / b; // Should be 3 + i

	cout << "A: " << a.toString() << endl;
	cout << "B: " << b.toString() << endl;
	cout << "C: " << c.toString() << endl;
	cout << "D: " << d.toString() << endl;
	cout << "E: " << e.toString() << endl;
	cout << "F: " << f.toString() << endl;
	cout << "G: " << g.toString() << endl;

	return 0;
}