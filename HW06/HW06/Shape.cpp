/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include "Shape.h"
#include <string>
#include <iostream>

using namespace std;

Shape::Shape()
{
	name = "N/A";
}

Shape::Shape(string s) {
	name = s;
}

void Shape::printShapeName()
{
	cout << name << endl;
}

void Shape::print()
{
	cout << name << endl;
}

double Shape::area()
{
	return 0.0;
}

double Shape::volume()
{
	return 0.0;
}