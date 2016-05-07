/*
*	Homework assignment 5, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include "ProductionWorker.h"
#include <string>

using namespace std;

ProductionWorker::ProductionWorker()
{
	name = "Joyce Z";
	hireDate = "November 9th, 1998";
	number = 0;
	shift = 1;
	payRate = 0;
}

ProductionWorker::ProductionWorker(int n)
{
	name = "Joyce Z";
	hireDate = "November 9th, 1998";
	number = n;
	shift = 1;
	payRate = 0;
}

ProductionWorker::ProductionWorker(int n, double d)
{
	name = "Joyce Z";
	hireDate = "November 9th, 1998";
	number = n;
	shift = 1;
	payRate = d;
}

ProductionWorker::ProductionWorker(double d)
{
	name = "Joyce Z";
	hireDate = "November 9th, 1998";
	number = 0;
	shift = 1;
	payRate = d;
}

ProductionWorker::ProductionWorker(string s)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = 0;
	shift = 1;
	payRate = 0;
}

ProductionWorker::ProductionWorker(string s, double d)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = 0;
	shift = 1;
	payRate = d;
}

ProductionWorker::ProductionWorker(string s, int n)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = n;
	shift = 1;
	payRate = 0;
}

ProductionWorker::ProductionWorker(string s, int n, double d)
{
	name = s;
	hireDate = "November 9th, 1998";
	number = n;
	shift = 1;
	payRate = d;
}

ProductionWorker::ProductionWorker(string s, string f, int n)
{
	name = s;
	hireDate = f;
	number = n;
	shift = 1;
	payRate = 0;
}

ProductionWorker::ProductionWorker(string s, string f, int n, double d)
{
	name = s;
	hireDate = f;
	number = n;
	shift = 1;
	payRate = d;
}

ProductionWorker::ProductionWorker(string s, string f, int n, int a)
{
	name = s;
	hireDate = f;
	number = n;
	shift = a;
	payRate = 0;
}

ProductionWorker::ProductionWorker(string s, string f, int n, int, double d)
{
	name = s;
	hireDate = f;
	number = n;
	shift = 1;
	payRate = d;
}

int ProductionWorker::getShift()
{
	return shift;
}

double ProductionWorker::getPayRate()
{
	return payRate;
}

void ProductionWorker::setShift(int a)
{
	shift = a;
}

void ProductionWorker::setPayRate(double d)
{
	payRate = d;
}

string ProductionWorker::toString() {
	return "\tName: " + name + "\n\tHire Date: " + hireDate + "\n\tNumber: " + to_string(number) + "\n\tShift: " + ((shift == 1) ? "Day" : "Night") + "\n\tPay Rate: " + to_string(payRate);
}