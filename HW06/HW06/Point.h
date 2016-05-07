/*
*	Homework assignment 6, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#pragma once
#include "Shape.h"
class Point :
	public Shape
{
private:
	int x;
	int y;
public:
	Point();
	Point(int, int);

	int getX();
	int getY();

	void setX(int);
	void setY(int);

	string toString();
};