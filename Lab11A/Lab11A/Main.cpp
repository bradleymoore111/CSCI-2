#include "MathStack.h"
#include <iostream>

using namespace std;

int main() {
	MathStack a = MathStack();

	for (int i = 0; i < 20; i++) {
		a.push(i + 1);
	}
	cout << "Going to run add(), then pop the result on a stack containing numbers 1-20" << endl;
	while (a.hasNext()) {
		a.add();
		cout << a.pop() << endl;
	}


	for (int i = 0; i < 20; i++) {
		a.push(i + 1);
	}
	cout << "Going to run sub(), then pop the result on a stack containing numbers 1-20" << endl;
	while (a.hasNext()) {
		a.sub();
		cout << a.pop() << endl;
	}


	for (int i = 0; i < 20; i++) {
		a.push(i + 1);
	}
	cout << "Going to run mult(), then pop the result on a stack containing numbers 1-20" << endl;
	while (a.hasNext()) {
		a.mult();
		cout << a.pop() << endl;
	}


	for (int i = 0; i < 20; i++) {
		a.push(i + 1);
	}
	cout << "Going to run div(), then pop the result on a stack containing numbers 1-20" << endl;
	while (a.hasNext()) {
		a.div();
		cout << a.pop() << endl;
	}


	for (int i = 0; i < 20; i++) {
		a.push(i + 1);
	}
	cout << "Going to run addAll(), then pop the result on a stack containing numbers 1-20" << endl;
	while (a.hasNext()) {
		a.addAll();
		cout << a.pop() << endl;
	}


	for (int i = 0; i < 10; i++) {
		a.push(i + 1);
	}
	cout << "Going to run multAll(), then pop the result on a stack containing numbers 1-10" << endl;
	while (a.hasNext()) {
		a.multAll();
		cout << a.pop() << endl;
	}
	
	return 0;
}