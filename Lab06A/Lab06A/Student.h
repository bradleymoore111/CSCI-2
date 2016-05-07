#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Student
{
protected:
	string name;
	Date birth;
public:
	Student();
	Student(string);
	Student(string, Date);

	void setName(string);
	void setBirth(Date);

	virtual string getName();
	virtual string getBirth();
};

