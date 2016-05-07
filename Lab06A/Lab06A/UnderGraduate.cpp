#include "UnderGraduate.h"
#include "Date.h"
#include <string>

using namespace std;

UnderGraduate::UnderGraduate() : Student()
{
	name = "Joyze Z";
	birth = Date(9, 11, 1998);
}

UnderGraduate::UnderGraduate(string s, Date d) : Student(s,d)
{
	name = s;
	birth = d;
}

string UnderGraduate::getName()
{
	return "I am an undergraduate and therefore am better than regular students, and my name is: " + name;
}

string UnderGraduate::getDate()
{
	return "I am an undergraduate and therefore am better than regular students, and the birth of Jesus Christ was: " + birth.toString();
}
