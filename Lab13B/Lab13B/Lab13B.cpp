#include <iostream>
#include <string>

using namespace std;

int main();
int sumArray(int*, int);
int multArgsInit(int, int);
int multArgs(int, int);

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	cout << "Sum of {1,2,3,4,5,6,7,8,9} = " << sumArray(a, 9) << endl;

	cout << "7 * 4 = " << multArgsInit(7, 4) << endl;
	cout << "-3 * 4 = " << multArgsInit(-3, 4) << endl;
	cout << "5 * -3 = " << multArgsInit(5, -3) << endl;

	return 0;
}

int sumArray(int* a, int b) {
	if (b > 1) {
		return *(a + b - 1) + sumArray(a, b - 1);
	}
	else {
		return *(a);
	}
}

int multArgsInit(int a, int b) {
	if (b < 0) {
		return multArgs(-a, -b);
	}
	else {
		return multArgs(a, b);
	}
}

int multArgs(int a, int b) {	
	if (b > 1) {
		return a + multArgs(a, b - 1);
	}
	else {
		return a;
	}
}