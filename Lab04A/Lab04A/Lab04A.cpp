#include <iostream>
#include <string>
#include "DayOfYear.h"

using namespace std;

int main() {
	DayOfYear a(2); // January 2
	DayOfYear b(32); // February 1
	DayOfYear c(361); // December 27
	DayOfYear d(365); // December 31

	cout << a.print() << ", " << b.print() << ", " << c.print() << ", and " << d.print() << endl;

	return 0;
}