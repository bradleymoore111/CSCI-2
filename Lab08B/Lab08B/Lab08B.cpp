#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	LinkedList test;
	test.addItem(0);
	test.addItem(1);
	cout << test.toString() << endl; // works
	for (int i = 0; i < 20; i++) {
		test.addItem(test.getItem(i) + test.getItem(i + 1));
	}
	cout << test.toString() << endl; // works

	test.delItem(5);
	test.delItem(10);

	cout << test.toString() << endl; // works

	test.delItem(0);
	test.delItem(test.size() - 1);

	cout << test.toString() << endl; // works

	test.insItem(3, 99999);

	cout << test.toString() << endl; // nope, fucked up before this

	test.insItem(5, 99999);

	cout << test.toString() << endl;

	test.clear();

	cout << test.toString() << endl;
	return 0;
}