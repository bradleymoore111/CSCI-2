/*
*	Homework assignment 13, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include "EmployeeInfo.h"
#include <string>

using namespace std;

EmployeeInfo::EmployeeInfo()
{
	ID = 0;
	name = "";
}

EmployeeInfo::EmployeeInfo(int a, string b) {
	ID = a;
	name = b;
}

int EmployeeInfo::getID() {
	return ID;
}

string EmployeeInfo::getName() {
	return name;
}

void EmployeeInfo::setID(int a) {
	ID = a;
}

void EmployeeInfo::setname(string a) {
	name = a;
}