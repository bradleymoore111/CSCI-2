/*
*	Homework assignment 5, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
#include "Employee.h"
#include <string>

using namespace std;

class ProductionWorker : public Employee
{
protected:
	int shift;
	double payRate;
public:
	ProductionWorker();
	ProductionWorker(double);
	ProductionWorker(int);
	ProductionWorker(int, double);
	ProductionWorker(string);
	ProductionWorker(string, double);
	ProductionWorker(string, int);
	ProductionWorker(string, int, double);
	ProductionWorker(string, string, int);
	ProductionWorker(string, string, int, double);
	ProductionWorker(string, string, int, int);
	ProductionWorker(string, string, int, int, double);


	int getShift();
	double getPayRate();

	void setShift(int);
	void setPayRate(double);

	string toString();
};