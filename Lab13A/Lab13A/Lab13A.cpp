#include <iostream>
#include <string>

using namespace std;

int recursiveFactorial(int);
int iterativeFactorial(int);

int main() {
	cout << recursiveFactorial(10) << endl;
	cout << recursiveFactorial(16) << endl;

	cout << iterativeFactorial(10) << endl;
	cout << iterativeFactorial(16) << endl;

	return 0;
}

int recursiveFactorial(int n) {
	if (n > 1) {
		cout << n << " * ";
		return n * recursiveFactorial(n - 1);
	}
	else {
		cout << "1 = ";
		return n;
	}
}

int iterativeFactorial(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	cout << n << "! = ";
	return sum;
}