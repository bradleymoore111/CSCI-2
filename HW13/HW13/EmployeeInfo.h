/*
*	Homework assignment 13, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
#include <string>

using namespace std;

class EmployeeInfo
{
private:
	int ID;
	string name;
public:
	EmployeeInfo();
	EmployeeInfo(int, string);
	int getID();
	string getName();
	void setID(int);
	void setname(string);
};

