/*
*	Homework assignment 8, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>
#include "TestScores.h"

using namespace std;

int main() {
	int test[4][10] = {
		{   1,  2,	3,	4,	5,	6,	7,	8,	9,	10 },
		{   90,	95, 90, 94, 89, 88, 85, 95, 99, 92 },
		{   75,	100,120,98, 150,101,148,405,2,	6  }, // cheater
		{   -50,-50,-50,-50,-50,-50,-50,-50,-50,-50}, // he tried
	};

	for (int i = 0; i < 4; i++) {
		try {
			TestScores a(test[i], 10); // attempting to create
			cout << "Average score for tester " << i << " is " << a.averageScore() << endl;
		}
		catch (int ie) {
			cout << "Average score for tester " << i << " is <ERROR EXCEPTION THROWN WITH INT " << ie << ">" << endl;
		}
	}

	return 0;
}