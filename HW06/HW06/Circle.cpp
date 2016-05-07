/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include "Circle.h"
#include <string>
#include <iostream>

using namespace std;

Circle::Circle()
{
	c = Point(0, 0);
	r = 1;
}

Circle::Circle(Point p, int a)
{
	c = p;
	r = a;
}

int Circle::getRadius()
{
	return r;
}

void Circle::setRadius(int a)
{
	r = (a < 0) ? -1 * a : a;
}

double Circle::area()
{
	return 3.14159265358 * r * r;
}

string Circle::toString()
{
	return  "Circle at " + c.toString() + " with radius of " + to_string(r) + ", surface area of " + to_string(area()) + ", and volume of " + to_string(volume());
}