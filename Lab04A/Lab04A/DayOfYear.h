#pragma once

#include <string>

using namespace std;

class DayOfYear
{
private:
	int val;
public:
	static int daysOfMonths[];
	static string months[];
	string print();
	DayOfYear(int n);
};

