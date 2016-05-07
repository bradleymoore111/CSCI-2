#include <iostream>

using namespace std;

// Appears to swap the values, and return their sum.
int doSomething(int &x, int &y);
// Testing to see whether it performs the same function
int doSomething(int *x, int *y);

int main() {
	int a = 1, b = 2, c = 3, d = 4;

	cout << "Demonstrating initial usage with a = 1, and b = 2.\nThe call doSomething(a,b) should return 30, and swap them.\n\n$: doSomething(a,b): " << doSomething(a, b) << endl;
	cout << "\nNow demonstrating usage with references, using a = 3, and b = 4.\nThe call doSomething(a,b) should return 70, along with swapping them.\n\n$: doSomething(&a,&b): " << doSomething(&c, &d) << endl << endl;
	return 0;
};

int doSomething(int &x, int &y) {
	int temp = x;
	x = y * 10;
	y = temp * 10;
	return x + y;
};

int doSomething(int *x, int *y) {
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
};