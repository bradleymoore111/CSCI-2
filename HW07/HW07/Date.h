/*
*	Homework assignment 7, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#pragma once
#include <string>

using namespace std;
class Date
{
private:
	int day; // if 0, null
	int month; // if 0, null
	int year; // if 0, null
public:
	bool throwsExceptions;
	Date();
	Date(bool); // if true, throw exceptions on error. If not true, round down/up on error.

	int getDay();
	int getMonth();
	int getYear();

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	bool isLeapYear();
	static bool isLeapYear(int); // static, int 1-12 for months
	int daysInMonth();
	static int daysInMonth(int); // static, returns days in 1-12 months

	string toString(); // MDY
	string toStringDMY(); // DMY
	string toStringYMD(); // YMD
	string toStringYDM(); // YDM
	string toStringMDY(); // MDY, redundant
};