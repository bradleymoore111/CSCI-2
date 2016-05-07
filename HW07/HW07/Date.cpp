/*
 *	Homework assignment 7, by Bradley Moore, in CSCI-2-0118
 *	Email: bradleym007@gmail.com
 *	Phone: 310-906-6659
 *	Github: github.com/trashy111
 */
#include "Date.h"
#include <string>

using namespace std;

static const int daysInMonths[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
static const string monthsString[13] = { "Null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	throwsExceptions = false;
}

Date::Date(bool a)
{
	day = 0;
	month = 0;
	year = 0;
	throwsExceptions = a;
}

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
	int d = daysInMonth(); // days in current month
	if (a < 0) {
		if (throwsExceptions) {
			throw a;
		}
		else {
			day = 0; // round up
		}
	}
	else if (a > d) {
		if (throwsExceptions) {
			throw a;
		}
		else {
			day = d; // round down
		}
	}
	else {
		day = d;
	}
}

void Date::setMonth(int a)
{
	if (a < 0) {
		if (throwsExceptions) {
			throw a;
		}
		else {
			month = 0;
		}
	}
	else if (a > 12) {
		if (throwsExceptions) {
			throw a;
		}
		else {
			month = 12;
		}
	}
	else {
		month = a;
	}

	setDay(day);
}

void Date::setYear(int a)
{
	year = a;
}

bool Date::isLeapYear()
{
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;
	else
		return false;
}

bool Date::isLeapYear(int a)
{
	if (a % 400 == 0)
		return true;
	else if (a % 100 == 0)
		return false;
	else if (a % 4 == 0)
		return true;
	else
		return false;
}

int Date::daysInMonth()
{
	if (month == 2 && isLeapYear()) {
		return 29;
	}
	return daysInMonths[month];
}

int Date::daysInMonth(int a)
{
	if (a == 2 && isLeapYear(a)) {
		return 29;
	}
	return daysInMonths[a];
}

string Date::toString()
{
	return monthsString[month] + " " + to_string(day) + ", " + to_string(year);
}

string Date::toStringDMY()
{
	return to_string(day) + " " + monthsString[month] + ", " + to_string(year);
}

string Date::toStringYMD()
{
	return to_string(year) + " " + monthsString[month] + ", " + to_string(day);
}

string Date::toStringYDM()
{
	return to_string(year) + " " + to_string(day) + ", " + monthsString[month];
}

string Date::toStringMDY()
{
	return toString();
}