/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include "Point.h"
#include <string>
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0; y = 0;
}

Point::Point(int a, int b)
{
	x = a; y = b;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::setX(int a)
{
	x = a;
}

void Point::setY(int b)
{
	y = b;
}

string Point::toString()
{
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}