#include "Date.h"
#include <string>

using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
	setDay(a);
	setMonth(b);
	setYear(c);
}

int Date::daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string Date::months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int a)
{
	if (a < 1) {
		day = 1;
	}

	else if (a > daysInMonths[month - 1]) {
		day = daysInMonths[month - 1];
	}

	else {
		day = a;
	}
}

void Date::setMonth(int b)
{
	if (b < 1) {
		month = 1;
	}

	else if (b > 12) {
		month = 12;
	}

	else {
		month = 12;
	}

	setDay(day);
}

void Date::setYear(int c)
{
	year = c;
}

string Date::toString()
{
	string s = months[month - 1];
	s += " " + to_string(day) + ", " + to_string(year);
	return s;
}

string Date::toString(int a, int b, int c)
{
	string s = months[b - 1];
	s += " " + to_string(a) + ", " + to_string(c);
	return s;
	return string();
}
