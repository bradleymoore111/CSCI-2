#include "TestScores.h"

using namespace std;

TestScores::TestScores()
{
	scores = 0; // null pointer
	size = 0;
}

TestScores::TestScores(int *a, int b)
{
	for (int i = 0; i < b; i++) {
		if (*(a + i) < 0 || *(a + i) > 100) {
			throw *(a + i);
		}
	}

	scores = a;
	size = b;
}

void TestScores::setScores(int *a, int b)
{
	for (int i = 0; i < b; i++) {
		if (*(a + i) < 0 || *(a + i) > 100) {
			throw *(a + i); // throw invalid score
		}
	}

	scores = a;
	size = b;
}

int TestScores::getScore(int i)
{
	return *(scores + i);
}

int TestScores::averageScore()
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(scores + i);
	}
	return sum / size;
}
