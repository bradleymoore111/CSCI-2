#include "StaticStack.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	StaticStack<int> stackA(10);
	StaticStack<double> stackB(10);
	StaticStack<char> stackC(10);

	int i = 0;
	while (!stackA.isFull()) {
		stackA.push((int)pow(i, 2));
		i++;
	}

	i = 0;
	while (!stackB.isFull()) {
		stackB.push(pow(2, i));
		i++;
	}

	i = 0;
	while (!stackC.isFull()) {
		stackC.push(65 + i);
		i++;
	}

	while (!stackA.isEmpty()) {
		cout << stackA.pop() << endl;
	}
	cout << endl;

	while (!stackB.isEmpty()) {
		cout << stackB.pop() << endl;
	}
	cout << endl;

	while (!stackC.isEmpty()) {
		cout << stackC.pop();
	}
	cout << endl;

	return 0;
}