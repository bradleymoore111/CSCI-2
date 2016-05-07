/*
*	Homework assignment 5, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include "Employee.h"
#include <string>

using namespace std;

Employee::Employee()
{
	name = "Joyce Z";
	hireDate = "November 9th, 1998";
	number = 0;
}

Employee::Employee(string s)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = 0;
}

Employee::Employee(string s, int n)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = n;
}

Employee::Employee(string s, string f, int n)
{
	name = s;
	hireDate = f;
	number = n;
}

Employee::Employee(int n)
{
	name = "Joyze Z";
	hireDate = "November 9th, 1998";
	number = n;
}

string Employee::getName()
{
	return name;
}

string Employee::getHireDate()
{
	return hireDate;
}

int Employee::getNumber()
{
	return number;
}

void Employee::setName(string s)
{
	name = s;
}

void Employee::setHireDate(string f)
{
	hireDate = f;
}

void Employee::setNumber(int n)
{
	number = n;
}

string Employee::toString() {
	return "\tName: " + name + "\n\tHire Date: " + hireDate + "\n\tNumber: " + to_string(number);
}