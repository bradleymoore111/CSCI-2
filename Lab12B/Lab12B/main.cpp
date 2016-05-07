#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

bool checkQueues(Queue<char>, Queue<char>);

int main() {
	while (true) {
		cout << "Time to compare 2 sentences :) enter \"HELP ME PLEASE\" to exit.\nPlease input sentence one:" << endl;

		Queue<char> a = Queue<char>();
		string s;
		getline(cin, s);

		if (s.compare("HELP ME PLEASE") == 0) {
			break;
		}

		for (int i = 0; i < s.length(); i++) {
			a.push(s[i]);
		}

		cout << "Now please input sentence two:" << endl;
		getline(cin, s);

		Queue<char> b = Queue<char>();
		for (int i = 0; i < s.length(); i++) {
			b.push(s[i]);
		}

		if (checkQueues(a, b)) {
			cout << "The sentences are identical" << endl;
		}
		else {
			cout << "The sentences are not identical" << endl;
		}
	}

	cout << "Take care" << endl;

	return 0;
}

bool checkQueues(Queue<char> a, Queue<char> b) {
	while (a.hasNext() && b.hasNext()) {
		if (a.pop() == b.pop()) {
			continue;
		}
		else {
			return false;
		}
	}

	return a.isEmpty() && b.isEmpty();
}