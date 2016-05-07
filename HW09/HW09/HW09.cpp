/*
*	Homework assignment 9, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList<int> list;

	list.add(0);
	list.add(1);

	for (int i = 0; i < 18; i++) {
		list.add(list.get(i) + list.get(i + 1));
	}

	int toInsert[] = { 1,2,3,4,5,6,7,8,9 };
	list.mergeArray(toInsert, 9, 10); // insert into location 10
	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}

	return 0;
}