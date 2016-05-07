/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#pragma once
#include "Circle.h"
#include <string>
#include <iostream>

using namespace std;

class Cylinder :
	public Circle
{
protected:
	int h;
public:
	Cylinder();
	Cylinder(Point, int, int); // Center, radius, height

	int getHeight();
	void setHeight(int);

	double area();
	double volume();

	string toString();
};