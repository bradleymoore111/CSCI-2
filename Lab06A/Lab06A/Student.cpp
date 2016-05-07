#include "Student.h"
#include "Date.h"
#include <string>

using namespace std;

Student::Student()
{
	name = "Joyce Z";
	birth = Date(9, 11, 1998);
}

Student::Student(string s)
{
	name = s;
	birth = Date(9, 11, 1998);
}

Student::Student(string s, Date d)
{
	name = s;
	birth = d;
}

void Student::setName(string s)
{
	name = s;
}

void Student::setBirth(Date d)
{
	birth = d;
}

string Student::getName()
{
	return name;
}

string Student::getBirth()
{
	return birth.toString();
}
