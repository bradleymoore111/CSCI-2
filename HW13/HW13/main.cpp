/*
*	Homework assignment 13, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <iostream>
#include <string>
#include "EmployeeInfo.h"
#include "BinaryTree.h"

using namespace std;

int main() {
	string names[] = { "John Williams", "Bill Witherspoon", "Jennifer Twain", "Sophia Lancaster", "Debbie Reece", "George McMullen", "Ashley Smith", "Josh Plemmons" };
	int IDs[] = { 1021, 1057, 2487, 3769, 1017, 1275, 1899, 4218 };

	BinaryTree a;
	for (int i = 0; i < 8; i++) {
		EmployeeInfo t(IDs[i], names[i]);
		a.insert(t);
	}

	a.balanceTree();

	while (true) {
		cout << "Welcome to Bradley's employee database." << endl << endl;
		cout << "Please select an option:\n\t1. Add an employee\n\t2. Find an employee\n\t3. Exit" << endl;

		cout << "\nOption: ";
		int n;
		cin >> n;

		if (n == 3) {
			break;
		}
		else if (n == 2) {
			cout << "What is the ID?" << "\nID: ";
			int ID;
			cin >> ID;

			EmployeeInfo emp = a.search(ID);
			cout << "\nThe name of user:" << ID << " is " << emp.getName() << "\n\n" << endl;
		}
		else if (n == 1) {
			cin.ignore();
			cout << endl << "\nWhat is the name of the new user?" << endl;
			cout << "Please enter your full name: ";
			string name;
			getline(cin, name);

			cout << "What is the ID of the new user?" << "\nID: ";
			int ID;
			cin >> ID;

			EmployeeInfo h(ID, name);
			a.insert(h);
			a.balanceTree();
		}
	}
	return 0;
}