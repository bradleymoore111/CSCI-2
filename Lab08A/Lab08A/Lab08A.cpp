#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	LinkedList test;
	test.addItem(0);
	test.addItem(1);
	cout << test.toString() << endl;
	for (int i = 0; i < 20; i++) {
		test.addItem(test.getItem(i) + test.getItem(i + 1));
	}
	cout << test.toString() << endl;

	test.delItem(5);
	test.delItem(10);

	cout << test.toString() << endl;

	test.delItem(0);

	cout << test.getItem(0) << endl;

	test.delItem(test.size() - 1);
	
	cout << test.toString() << endl;
	
	return 0;
}