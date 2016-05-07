/*
*	Homework assignment 5, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;

int main() {
	Employee a;
	Employee b("Japooty", "Nov 9th, 1998", 420);

	ProductionWorker c("CLam", 1011484);
	ProductionWorker d("Idk, some name", "a long time ago, in a galaxy far far away", 1011484, 2, 101.14840482);

	cout << "Testing Employee Accessor a: " << endl << a.toString() << endl;
	cout << "Testing Employee Accessor b: " << endl << b.toString() << endl;
	cout << "Testing ProductionWorker accessor c: " << endl << c.toString() << endl;
	cout << "Testing ProductionWorker accessor d: " << endl << d.toString() << endl;
	 

	return 0;
}