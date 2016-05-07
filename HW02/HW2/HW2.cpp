/*
*	Homework assignment 2, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

// Standard importing/setting stuff up/defining functions
#include <iostream>

using namespace std;

double median(double* array, int size);

// Main function, purely for testing purposes
int main() {

	// Creating 4 arrays with which to test, while they each have 20 elements, they will be treated as if the first and third have 20 elements, while the second and fourth have 19 (to test even/odd median calculation)
	double exampleArray[4][20] = {
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  }, // last element is ignored
		{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10,10 },
		{ 1.001, 1.002, 1.003, 1.004, 1.005, 1.006, 1.007, 1.008, 1.009, 1.01, 1.011, 1.012, 1.013, 1.014, 1.015, 1.016, 1.017, 1.018, 1.019, 1.02 }, // last element is ignored
	};

	// Testing each. The outputs should be 10.5, 1, 5.5, and 1.01
	for (int i = 0; i < 4; i++) {
		cout << "Median of Array[" << (i + 1) << "] is " << median(exampleArray[i], ((i % 2 == 0) ? 20 : 19)) << endl;
	}

	return 0;
}

double median(double* array, int size) {
	// Defining bounds, working from out in
	int begin = 0;
	size--;

	// Working towards each other, if they pass each other something REALLY bad happened
	while (begin <= size) {
		// Debugging
		// cout << "\tRunning with *(array + begin) = " << *(array + begin) << ", begin = " << begin << ", and size = " << size << endl;

		// If they reach each other, then they by definition are at the median.
		if (begin == size) {
			return *(array + begin);
		}

		// If they are one away, the array must be an even size, and so we need to average the 2 values
		else if (begin + 1 == size) {
			return (*(array + begin) + *(array + size)) / 2.0;
		}

		// Incrementing them towards each other
		begin++;
		size--;
	}

	// should never be reached, assuming all inputs were done correctly
	return 0;
}