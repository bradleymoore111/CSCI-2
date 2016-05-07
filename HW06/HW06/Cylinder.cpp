/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include "Cylinder.h"
#include <iostream>
#include "Point.h"
#include <string>

using namespace std;

Cylinder::Cylinder()
{
	c = Point(0, 0);
	r = 0;
	h = 0;
}

Cylinder::Cylinder(Point a, int b, int d)
{
	c = a;
	r = b;
	h = d;
}

int Cylinder::getHeight()
{
	return h;
}

void Cylinder::setHeight(int a)
{
	h = a;
}

double Cylinder::area()
{
	return 2 * 3.14159265 * r * r + 2 * 3.14159265 * r * h;
}

double Cylinder::volume()
{
	return 3.14159265 * r * r * h;
}

string Cylinder::toString()
{
	string s = "Cylinder at " + c.toString() + " with height of " + to_string(h) + ", radius of " + to_string(r) + ", surface area of " + to_string(area()) + ", and volume of " + to_string(volume());
	return s;
}