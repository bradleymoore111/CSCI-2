#include <iostream>
#include <string>
#include "UnderGraduate.h"
#include "Student.h"
#include "Date.h"

using namespace std;

int main() {
	Student a("Bread",Date(11, 11, 1997));
	UnderGraduate b("Julia", Date(25, 10, 2006));

	cout << "Student: " << a.getBirth() << ", " << a.getName() << endl;
	cout << "Undergraduate: " << b.getDate() << ", " << b.getName() << endl;
	return 0;
}