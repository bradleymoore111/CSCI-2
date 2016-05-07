#pragma once
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);

	int getDay();
	int getMonth();
	int getYear();

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	string toString();
	
	static string toString(int, int, int);
	static string months[12];
	static int daysInMonths[12];
};

