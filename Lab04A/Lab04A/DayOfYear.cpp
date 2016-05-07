#include "DayOfYear.h"
#include <string>

using namespace std;

DayOfYear::DayOfYear(int n) {
	val = (n-1) % 365 + 1;
};

int DayOfYear::daysOfMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

string DayOfYear::print() {
	int a = DayOfYear::val;
	int i = 0;
	while (a > DayOfYear::daysOfMonths[i]) {
		a -= DayOfYear::daysOfMonths[i];
		i++;
	}
	return DayOfYear::months[i] + " " + to_string(a);
}