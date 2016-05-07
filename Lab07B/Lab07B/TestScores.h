/*
*	Homework assignment 8, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
class TestScores
{
private:
	int *scores;
	int size;
public:
	TestScores();
	TestScores(int*, int);

	void setScores(int*, int);
	int getScore(int);
	int averageScore();
};

