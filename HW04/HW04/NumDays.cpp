#include "NumDays.h"

NumDays::NumDays()
{
	hours = 0;
}

NumDays::NumDays(double n)
{
	hours = n;
}

double NumDays::getHours()
{
	return hours;
}

double NumDays::getDays()
{
	return hours / 8;
}

void NumDays::setHours(double n)
{
	hours = n;
}

void NumDays::setDays(double n)
{
	hours = n * 8;
}

NumDays NumDays::operator + (NumDays x)
{
	NumDays a(getHours() + x.getHours());
	return a;
}

NumDays NumDays::operator -(NumDays x) {
	NumDays a(getHours() - x.getHours());
	return a;
}

NumDays NumDays::operator ++() {
	setHours(getHours() + 1);
	return *this;
}

NumDays NumDays::operator ++(int) {
	setHours(getHours() + 1);
	return *this;
}

NumDays NumDays::operator --() {
	setHours(getHours() - 1);
	return *this;
}

NumDays NumDays::operator --(int) {
	setHours(getHours() - 1);
	return *this;
}