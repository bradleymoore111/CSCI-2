/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Shape
{
protected:
	string name;
public:
	Shape();
	Shape(string);

	virtual void printShapeName();
	virtual void print();

	virtual double area();
	virtual double volume();
};