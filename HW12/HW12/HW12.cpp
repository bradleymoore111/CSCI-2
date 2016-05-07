/*
*	Homework assignment 12, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>

using namespace std;

bool palindrome(string);
bool palindromeHelper(int, int, string);

string cleanString(string, int);

int main() {
	string s[6] = { "Able was I, ere I saw Elba","A man, a plan, a canal, Pamana","Desserts, I stressed","Kayak","CLam","This is not a palindrome" };
	// int l[6] = { 27, 31, 21, 6, 4, 25 }; // length of strings

	for (int i = 0; i < 6; i++) {
		cout << "Checking if string " << i + 1 << " is a palindrome" << endl;
		cout << "\tstring:\n\t\t" << s[i] << endl;
		cout << "\tpalindrome:\n\t\t" << ((palindrome(s[i]))?"true":"false") << endl;
	}
	return 0;
}

bool palindrome(string s) { // remove spaces and capitalization
	s = cleanString(s,s.length());

	cout << "\tcleanString:\n\t\t" << s << endl;

	return palindromeHelper(0, s.length() - 1, s);
}

string cleanString(string s,int b) {
	//cout << (s[b-1]) << endl;
	if (b > 1) {
		char a = s[b -1];
		if (a != ' ' && a!=',' && a!= '.') {
			return cleanString(s, b - 1) + string(1,tolower(a));
		}
		else {
			return cleanString(s, b - 1);
		}
	}
	else {
		char a = s[0];
		if (a != ' ') {
			return string(1,tolower(a));
		}
		else {
			return "";
		}
	}
}

bool palindromeHelper(int a, int b, string s) {
	if (a < b) {
		if (s[a] == s[b]) {
			return palindromeHelper(a + 1, b - 1, s);
		}
		else {
			return false;
		}
	}
	else { // (a == b || a < b)
		return true;
	}
}