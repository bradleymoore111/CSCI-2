#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

bool checkIfClose(string);
bool checkIfCloseParenthesesHelper(Stack<char>*);
bool checkIfCloseSquiglyHelper(Stack<char>*);
bool checkIfCloseSquareHelper(Stack<char>*);

int main() {
	// May we all pour out a drink to the god that has made recursion work
	string stuff1 = "This string (which is pretty cool) will have plenty of inner (meaning, intertwining (meaning, stacked (meaning, nested))) parentheses.";
	string stuff2 = "Given an expression string exp, examine whether the pairs and the orders of \"{\",\"}\",\"(\",\")\",\"[\",\"]\" are correct in exp. For example, the program should print 'balanced' for exp = \"[()]{}{[()()]()}\" and 'not balanced' for exp = \"[(])\"";
	string stuff3 = "this should fail ;}";
	string stuff4 = "{[({[({[( Here's really testing the money for you )]})]})]}";
	//Stack<char> stack = Stack<char>();

	cout << "Checking if stuff1 has matched parentheses: " << endl;
	cout << ((checkIfClose(stuff1)) ? "\ttrue" : "\tfalse") << endl;

	cout << "Checking if stuff2 has matched everything: " << endl;
	cout << ((checkIfClose(stuff2)) ? "\ttrue" : "\tfalse") << endl;

	cout << "Checking if stuff3 has matched everything: " << endl;
	cout << ((checkIfClose(stuff3)) ? "\ttrue" : "\tfalse") << endl;

	cout << "Checking if stuff4 has matched everything: " << endl;
	cout << ((checkIfClose(stuff4)) ? "\ttrue" : "\tfalse") << endl;


	cout << "\nWould you like to test your own? Enter it: " << endl;
	string input = "";
	getline(cin, input);
	cout << "Checking if the user knows what they're doing: " << endl;
	cout << ((checkIfClose(input)) ? "\ttrue" : "\tfalse") << endl;

	return 0;
}

bool checkIfClose(string sentence) {
	cout << "\t" << sentence << endl;
	Stack<char>* s = &Stack<char>();
	for (size_t i = 0; i < sentence.size(); i++) {
		(*s).push(sentence[i]);
	}

	while ((*s).hasNext()) {
		char curr = (*s).pop();

		if (curr == '(' || curr == '{' || curr == '[') {
			return false;
		}
		else if (curr == ')') {
			bool t = checkIfCloseParenthesesHelper(s);
			if (t == false) {
				cout << "\tError, parentheses mismatch" << endl;
				return t;
			}
		}
		else if (curr == '}') {
			bool t = checkIfCloseSquiglyHelper(s);
			if (t == false) {
				cout << "\tError, squigly mismatch" << endl;
				return t;
			}
		}
		else if (curr == ']') {
			bool t = checkIfCloseSquareHelper(s);
			if (t == false) {
				cout << "\tError, square mismatch" << endl;
				return t;
			}
		}
	}

	cout << "\tBalanced :)" << endl;
	return true;
}

bool checkIfCloseParenthesesHelper(Stack<char> * s) {
	while ((*s).hasNext()) {
		char curr = (*s).pop();
		if (curr == '(') {
			return true;
		}
		else if (curr == ')') {
			bool t = checkIfCloseParenthesesHelper(s);
			if (t == false) {
				cout << "\tError, parentheses mismatch" << endl;
				return t;
			}
		}
		else if (curr == '}') {
			bool t = checkIfCloseSquiglyHelper(s);
			if (t == false) {
				cout << "\tError, squigly mismatch" << endl;
				return t;
			}
		}
		else if (curr == ']') {
			bool t = checkIfCloseSquareHelper(s);
			if (t == false) {
				cout << "\tError, square mismatch" << endl;
				return t;
			}
		}
	}
	return false;
}

bool checkIfCloseSquiglyHelper(Stack<char>* s) {
	while ((*s).hasNext()) {
		char curr = (*s).pop();
		if (curr == '{') {
			return true;
		}
		else if (curr == ')') {
			bool t = checkIfCloseParenthesesHelper(s);
			if (t == false) {
				cout << "\tError, parentheses mismatch" << endl;
				return t;
			}
		}
		else if (curr == '}') {
			bool t = checkIfCloseSquiglyHelper(s);
			if (t == false) {
				cout << "\tError, squigly mismatch" << endl;
				return t;
			}
		}
		else if (curr == ']') {
			bool t = checkIfCloseSquareHelper(s);
			if (t == false) {
				cout << "\tError, square mismatch" << endl;
				return t;
			}
		}
	}
	return false;
}

bool checkIfCloseSquareHelper(Stack<char>* s) {
	while ((*s).hasNext()) {
		char curr = (*s).pop();
		if (curr == '[') {
			return true;
		}
		else if (curr == ')') {
			bool t = checkIfCloseParenthesesHelper(s);
			if (t == false) {
				cout << "\tError, parenetheses mismatch" << endl;
				return t;
			}
		}
		else if (curr == '}') {
			bool t = checkIfCloseSquiglyHelper(s);
			if (t == false) {
				cout << "\tError, squigly mismatch" << endl;
				return t;
			}
		}
		else if (curr == ']') {
			bool t = checkIfCloseSquareHelper(s);
			if (t == false) {
				cout << "\tError, square mismatch" << endl;
				return t;
			}
		}
	}
	return false;
}