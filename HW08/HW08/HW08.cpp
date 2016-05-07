/*
*	Homework assignment 8, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList list;

	list.addItem(0);
	list.addItem(1);

	for (int i = 0; i < 18; i++) {
		list.addItem(list.getItem(i) + list.getItem(i + 1));
	}

	cout << list.toString() << endl;

	list.reverse();

	cout << list.toString() << endl;

	return 0;
}