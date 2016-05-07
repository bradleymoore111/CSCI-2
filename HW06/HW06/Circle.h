/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#pragma once
#include "Point.h"
#include <string>
#include <iostream>

using namespace std;

class Circle :
	public Point
{
protected:
	Point c;
	int r; // radius
public:
	Circle();
	Circle(Point, int);

	int getRadius();
	void setRadius(int);
	double area();
	string toString();
};