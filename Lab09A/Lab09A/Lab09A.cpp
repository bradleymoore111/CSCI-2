#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	LinkedList<int> list;
	list.add(0);
	list.add(1);
	for (int i = 0; i < 18; i++) {
		list.add(list.get(i) + list.get(i + 1));
	}

	cout << "Locations of numbers 1-35:" << endl;

	for (int i = 1; i <= 35; i++) {
		int n = list.find(i);
		cout << "\t" << ((i<10)?(" "+to_string(i)):to_string(i)) << " is at index: " << ((n < 0)?"-1":(" " + to_string(n))) << endl;
	}

	return 0;
}