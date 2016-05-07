#pragma once
#include "Student.h"
#include <string>

using namespace std;

class UnderGraduate : public Student
{
public:
	UnderGraduate();
	UnderGraduate(string, Date);
	string getName();
	string getDate();
};