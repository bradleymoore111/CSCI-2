/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include <iostream>
#include <string>
#include "Circle.h"
#include "Cylinder.h"
#include "Point.h"
#include "Shape.h"

using namespace std;

int main() {
	Circle a;
	Circle b(Point(1, 3), 3);
	Cylinder c;
	Cylinder d(Point(2, -4), 3, 4);
	Point e;
	Point f(4, 5);

	cout << "\nThe Circles:\n\tDefault:\n\t\t" << a.toString() << "\n\tCustom:\n\t\t" << b.toString() << endl;
	cout << "\nThe Cylinders:\n\tDefault:\n\t\t" << c.toString() << "\n\tCustom:\n\t\t" << d.toString() << endl;
	cout << "\nThe Points:\n\tDefault:\n\t\t" << e.toString() << "\n\tCustom:\n\t\t" << f.toString() << endl;
	return 0;
}