#include "StaticStack.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	StaticStack<int> s(5);

	int nums[] = { 10,20,30,40,50 };

	for (int i = 0; i < 5; i++) {
		s.push(nums[i]);
	}

	while (!s.isEmpty()) {
		cout << s.pop() << endl;
	}

	return 0;
}