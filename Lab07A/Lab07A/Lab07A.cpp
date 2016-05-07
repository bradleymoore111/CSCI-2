#include <iostream>

using namespace std;

template <class T>
T minimum(T a, T b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

template <class T>
T maximum(T a, T b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	cout << minimum<int>(1, 2) << endl; // testing ints, should output 1
	cout << minimum<int>(0, -600) << endl; // testing ints, should output -600

	cout << minimum<char>('a', 'b') << endl; // Undefined behavior. Not even sure what will happen

	cout << minimum<double>(0.0001, 0.0002) << endl; // testing doubles, should output 0.0001

	cout << maximum<int>(1, 2) << endl; // testing ints, should output 2
	cout << maximum<int>(0, -600) << endl; // testing ints, should output 0

	cout << maximum<char>('a', 'b') << endl; // Undefined behavior. Not even sure what will happen

	cout << maximum<double>(0.0001, 0.0002) << endl; // testing doubles, should output 0.0002
	return 0;
}