/*
*	Homework assignment 7, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

int main() {
	Date dArray[8];
	for (int i = 0; i < 6; i++) {
		dArray[i].throwsExceptions = true;
		dArray[i].setYear(1999 + i);
		dArray[i].setMonth(2); // Testing february for leap year
	}

	dArray[6].setMonth(2);
	dArray[6].setYear(1600);
	dArray[7].setMonth(2);
	dArray[7].setYear(-5);

	// testing leap year
	cout << "Testing setting the date to 29th of February. If it sets it to 28th, it was rounded down. Otherwise it'll log an exception and not set the date." << endl;
	for (int i = 0; i < 8; i++) {
		try {
			dArray[i].setDay(29); // Can only be set if leap year. Otherwise, should throw exception or round
			cout << dArray[i].toString() << endl;
		}
		catch (int ie) {
			cout << dArray[i].toString() << ". Exception thrown with int " << ie << endl;
		}
	}

	// testing November 9th
	cout << "\nTesting November 9th" << endl;
	for (int i = 0; i < 3; i++) {
		dArray[i].setMonth(11);
		try {
			dArray[i].setDay(9 * (i + 1) + 9); // should be legal until the last moment
			cout << dArray[i].toString() << endl;
		}
		catch (int ie) {
			cout << dArray[i].toString() << ". Exception thrown with int " << ie << endl;
		}
	}
	cout << "\nGood bye :)" << endl;

	return 0;
}
