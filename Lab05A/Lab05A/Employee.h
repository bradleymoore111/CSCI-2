/*
*	Homework assignment 5, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
#include <string>

using namespace std;

class Employee
{
protected:
	string name;
	string hireDate;
	int number;
public:
	Employee();
	Employee(string);
	Employee(string, int);
	Employee(string, string, int);
	Employee(int);

	string getName();
	string getHireDate();
	int getNumber();

	void setName(string);
	void setHireDate(string);
	void setNumber(int);

	string toString();
};