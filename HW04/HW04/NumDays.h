#pragma once
class NumDays
{
private:
	double hours;
public:
	NumDays();
	NumDays(double);
	double getHours();
	double getDays();
	void setHours(double);
	void setDays(double);

	NumDays operator+(NumDays x);
	NumDays operator-(NumDays);
	NumDays operator++();
	NumDays operator++(int);
	NumDays operator--();
	NumDays operator--(int);
};