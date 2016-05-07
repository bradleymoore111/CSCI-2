#include "ComplexNumber.h"
#include <string>

using namespace std;

ComplexNumber::ComplexNumber()
{
	real = 0;
	nonreal = 0;
}

ComplexNumber::ComplexNumber(double a, double b)
{
	real = a;
	nonreal = b;
}

double ComplexNumber::getReal()
{
	return real;
}

double ComplexNumber::getNonReal()
{
	return nonreal;
}

void ComplexNumber::setReal(double a)
{
	real = a;
}

void ComplexNumber::setNonReal(double b)
{
	nonreal = b;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber x)
{
	ComplexNumber c(real + x.getReal(), nonreal + x.getNonReal());
	return c;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber x)
{
	ComplexNumber c(real - x.getReal(), nonreal - x.getNonReal());
	return c;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber x)
{
	ComplexNumber c;
	c.setReal(real*x.getReal() - nonreal*x.getNonReal());
	c.setNonReal(real*x.getNonReal() + nonreal*x.getReal());
	return c;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber x)
{
	ComplexNumber c;
	c.setReal((real*x.getReal() + nonreal*x.getNonReal()) / (x.getReal()*x.getReal() + x.getNonReal()*x.getNonReal()));
	c.setNonReal((nonreal*x.getReal() - real*x.getNonReal()) / (x.getReal()*x.getReal() + x.getNonReal()*x.getNonReal()));
	return c;
}

string ComplexNumber::toString()
{
	string s = "(";
	s += to_string(real);
	s += ", ";
	s += to_string(nonreal);
	s += "i)";
	return s;
}
