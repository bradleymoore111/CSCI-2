/*
*	Homework assignment 2, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

// Basic imports, iostream for i/o, iomanip for small formatting, math.h for pow.
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// Defining the class
class Payment {
	// Initializing all private vars (don't want direct access to vars).
private:
	double principal; // Dollar amount of the loan
	double rate; // Annual interest rate
	int term; // The number of years of the loan

public:

	// Accessors
	double getPrincipal() {
		return principal;
	}
	double getRate() {
		return rate;
	}
	int getTerm() {

	}

	// Modifiers
	void setPrincipal(double a) {
		principal = a;
	}
	void setRate(double a) { // Enter as a number, effectively the percent
		rate = a / 1200.0;
	}
	void setTerm(int a) { // Enter as the year, like 30 or 15. This accounts for months.
		term = a * 12;
	}

	// Here are the important methods
	double getMonthlyPayment() {
		return principal * rate / (1.0 - pow(rate + 1, -1 * term));
	}
	double getTotalPaid() {
		return getMonthlyPayment() * term;
	}
	double getTotalInterest() {
		return getTotalPaid() - principal;
	}
};

int main()
{
	// Communication
	cout << "Welcome to Bradley's Mortgage Calculator.\nWe're going to input some numbers in order to figure out what you're talking about. Input a negative number at any time to disconnect.\n" << endl;
	// Defining one instance of the class to be used the entire time (possible implementation later could have multiple classes, if we ever have to write a bank)
	Payment p;
	while (true) {
		// Getting rate
		cout << "So, what's your rate? A single percentage (ie. 4) is the correct format. We'll do the conversions.\nRate: ";
		double a;
		cin >> a;
		if (a < 0.0)
			break;
		p.setRate(a);

		// Getting principal
		cout << "\nAwesome! Now, what was the principal for your loan?\nPrincipal: ";
		double b;
		cin >> b;
		if (b < 0.0)
			break;
		p.setPrincipal(b);

		// Getting term
		cout << "\nAlmost there :) What term are you on for your payment (assuming you haven't paid off any of your loan yet).\nTerm: ";
		int c;
		cin >> c;
		if (c < 0.0)
			break;
		p.setTerm(c);

		// Calculating
		cout << "\nAwesome. So, your monthly payment is $" << setprecision(2) << fixed << p.getMonthlyPayment() << ", and the total amount paid to the bank is $" << setprecision(2) << fixed << p.getTotalPaid() << ".\n\nHave a nice day!\n" << endl;
	}

	// <3
	cout << "Good bye :)" << endl;

	return 0;
}