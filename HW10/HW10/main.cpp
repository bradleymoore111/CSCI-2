/*
*	Homework assignment 10, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

class Inventory {
private:
	int serialNumber;
	int manufactDate;
	int lotNum;
public:
	Inventory() {
		serialNumber = 0;
		manufactDate = 0;
		lotNum = 0;
	}
	Inventory(int a, int b, int c) {
		serialNumber = a;
		manufactDate = b;
		lotNum = c;
	}

	int getSerialNumber() {
		return serialNumber;
	}
	int getManufactDate() {
		return manufactDate;
	}
	int getLotNum() {
		return lotNum;
	}

	void setSerialNumber(int a) {
		serialNumber = a;
	}
	void setManufactDate(int a) {
		manufactDate = a;
	}
	void setLotNum(int a) {
		lotNum = a;
	}
};

int main() {
	Stack<Inventory> s = Stack<Inventory>();

	while (true) {
		cout << string(5, '\n');
		cout << "Welcome to Trashy111's inventory :) would you like to: " << endl;
		cout << "\t1. Add an item\n\t2. View the top item\n\t3. Remove the top item\n\t4. Exit" << endl;
		cout << "Option: ";

		int choice;
		cin >> choice;

		cout << string(5, '\n');

		if (choice == 1) {
			cout << "Adding an item to the inventory." << endl;

			cout << "What is the serial number (int)? " << endl;
			int serial;
			cin >> serial;

			cout << "What is the date of manufacture (int)? " << endl;
			int date;
			cin >> date;

			cout << "What is the lot number (int)? " << endl;
			int lot;
			cin >> lot;

			Inventory i = Inventory(serial, date, lot);

			s.push(i);
		}
		else if (choice == 2) {
			cout << "Viewing the top of the inventory." << endl;

			bool doThis = true;
			Inventory i;
			try {
				i = s.peek();
			}
			catch (void*) {
				cout << "Error, inventory item not found." << endl;
				doThis = false;
			}
			if (doThis) {
				cout << "\tSerial Number: " << i.getSerialNumber() << endl;
				cout << "\tDate of Manufacture: " << i.getManufactDate() << endl;
				cout << "\tLot Number: " << i.getLotNum() << endl;
			}
		}
		else if (choice == 3) {
			cout << "You would like to delete the top item of the inventory, which is:" << endl;

			bool doThis = true;

			Inventory i;
			try {
				i = s.peek();
			}
			catch (void*) {
				cout << "Error, inventory item not found" << endl;
				doThis = false;
			}

			if (doThis) {
				cout << "\tSerial Number: " << i.getSerialNumber() << endl;
				cout << "\tDate of Manufacture: " << i.getManufactDate() << endl;
				cout << "\tLot Number: " << i.getLotNum() << endl;

				cout << "\nAre you sure (y/n)? " << endl;

				string b;
				cin >> b;

				if (b.compare("y") == 0) {
					s.pop();
					cout << "Deleted" << endl;
				}
			}
		}
		else if (choice == 4) {
			cout << "Good bye" << endl;
			system("pause");
			break;
		}
		else {
			cout << "I did not understand what you meant." << endl;
		}
		system("pause");
	}
}