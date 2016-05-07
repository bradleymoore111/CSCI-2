#pragma once

#include <string>

using namespace std;

class ComplexNumber
{
private:
	double real;
	double nonreal;
public:
	ComplexNumber();
	ComplexNumber(double, double);

	double getReal();
	double getNonReal();

	void setReal(double);
	void setNonReal(double);

	ComplexNumber operator+(ComplexNumber);
	ComplexNumber operator-(ComplexNumber);

	ComplexNumber operator*(ComplexNumber);
	ComplexNumber operator/(ComplexNumber);

	string toString();
};