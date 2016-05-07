/*
*	Homework assignment 4, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>
#include "NumDays.h"

using namespace std;

void outputNumDays(string s, NumDays a);

int main() {
	NumDays a(4.0); // lazy bum, 0.5 days
	NumDays b(40.0); // 8 hour week, 5 days
	NumDays c; // Empty args, 0 days

	NumDays d = b - a; // Should be 36 hours, or 4.5 days
	NumDays e = a + b; // Should be 44 hours, or 5.5 days

	c++; // Should now be 1 hour, 0.125 days
	a--; // Should now be 3 hours, 0.375 days

	outputNumDays("A: ", a); // ahould be 3 and 0.375
	outputNumDays("B: ", b); // should be 40 and 5
	outputNumDays("C: ", c); // should be 1 and 0.125
	outputNumDays("D: ", d); // should be 36 and 4.5
	outputNumDays("E: ", e); // should be 44 and 5.5

	return 0;
}

void outputNumDays(string s, NumDays a) {
	cout << s << endl;
	cout << "Hours:\t" << a.getHours() << endl;
	cout << "Days:\t" << a.getDays() << endl;
}