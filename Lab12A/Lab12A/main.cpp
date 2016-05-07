#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Please input a sentence: " << endl;
	string s;
	cin >> s;

	Queue<char> q = Queue<char>();

	for (int i = 0; i < s.length(); i++) {
		q.push(s[i]);
	}

	string b = "";

	for (int i = 0; i < s.length(); i++) {
		b += string(1,toupper(q.pop()));
	}

	cout << "Result:\n\t" << b << endl;
	return 0;
}