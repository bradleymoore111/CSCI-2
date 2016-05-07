#include <iostream>
#include <string>

using namespace std;

class TestScores {
private:
	int score1;
	int score2;
	int score3;
public:
	TestScores() {
		score1 = 0;
		score2 = 0;
		score3 = 0;
	}
	TestScores(int a, int b, int c) {
		score1 = a;
		score2 = b;
		score3 = c;
	}

	int getScore1() {
		return score1;
	}
	int getScore2() {
		return score2;
	}
	int getScore3() {
		return score3;
	}
	int getAverageScore() {
		return (score1 + score2 + score3) / 3;
	}

	void setScores(int a, int b, int c) {
		score1 = a;
		score2 = b;
		score3 = c;
	}
	void setScore1(int a) {
		score1 = a;
	}
	void setScore2(int b) {
		score2 = b;
	}
	void setScore3(int c) {
		score3 = c;
	}
};

int main() {
	cout << "Welcome to the test score lab!" << endl;

	TestScores t;
	int a, b, c;
	cout << "Please enter 3 test scores." << endl;
	cout << "\tTest score 1: ";
	cin >> a;
	cout << "\tTest score 2: ";
	cin >> b;
	cout << "\tTest score 3: ";
	cin >> c;

	t.setScores(a, b, c);

	cout << "\nYour overall average is " << t.getAverageScore() << endl;
	cout << "Have a nice day :)\n" << endl;
	return 0;
}