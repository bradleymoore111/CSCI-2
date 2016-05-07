/*
*	Homework assignment 13, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
#include <string>
#include "EmployeeInfo.h"
#include <iostream>

using namespace std;

template<class T>
class LinkedList
{

private:
	struct Node {
		T data;
		Node *next;
		Node *prev;
	};

	Node *head;
	Node *tail;

	int length;

public:
	LinkedList<T>()
	{
		head = nullptr;
		tail = nullptr;

		length = 0;
	}
	~LinkedList<T>()
	{
		clear();
	}

	void add(T a)
	{
		if (!head) {
			head = new Node;
			(*head).data = a;
			(*head).prev = nullptr;
			(*head).next = nullptr;

			tail = head;
			length++;
		}
		else {
			Node *temp = new Node;
			(*tail).next = temp; // this line fucks it up. awesome. OH HEY I THINK I KNOW WHY
			(*temp).data = a;
			(*temp).prev = tail;
			(*temp).next = nullptr;
			tail = temp;
			length++;
		}
	} // input is data to add

	void insert(int a, T b)
	{
		if (a > length) {
			throw a;
		}

		Node *temp;
		temp = head;
		for (int i = 0; i < a; i++) {
			temp = (*temp).next;
		}

		// need to shift this over one
		Node *temp2; // the new node to insert, temp is just a location node
		(*temp2).prev = (*temp).prev;
		(*((*temp).prev)).next = temp2;
		(*temp).prev = temp2; // set previous to point to this
		(*temp2).next = temp; // set this to point to next, basically squeezing itself in there
		(*temp2).data = b;
		length++;
	}
	T get(int a)
	{
		if (a > length - 1) {
			throw 0;
		}

		Node *temp;
		temp = head;
		for (int i = 0; i < a; i++) {
			temp = (*temp).next;
		}

		return (*temp).data;
	} // input is location
	T remove(int a)
	{
		if (a > length - 1) {
			throw 0;
		}

		int finalData;

		if (a == 0) { // if deleting first node
			Node *temp;
			temp = head;
			finalData = (*head).data;
			head = (*head).next;
			// delete temp; // need to clear up memory
			(*head).prev = nullptr;
		}

		else if (a < length - 1) { // deleting random node in memory

			Node *temp;
			temp = head;
			for (int i = 0; i < a - 1; i++) { // goes to location before it
				temp = (*temp).next;
			}

			Node *temp2;
			temp2 = (*temp).next;
			finalData = (*temp2).data;
			(*temp).next = (*((*temp).next)).next;
			(*((*temp).next)).prev = temp;
			delete temp2;
		}

		else { // deleting tail
			Node *temp = tail;
			(*((*tail).prev)).next = nullptr;
			finalData = (*tail).data;

			tail = (*tail).prev;
			delete temp;
		}

		length--;

		return finalData;
	} // input is location
	T set(int a, T b)
	{
		if (a > length - 1) {
			throw 0;
		}

		Node *temp;
		temp = head;
		for (int i = 0; i < a - 1; i++) { // goes to location before it
			temp = (*temp).next;
		}

		int b = (*temp).data;
		(*temp).data = b;

		return b;
	} // input is location

	bool find(T obj) {
		return -1;
	}
	//string toString() {
	//return "";
	//}

	T* toArray() { // assumed you know the size
		T* newArray = new T[length];

		Node* temp = head;
		for (int i = 0; i < length; i++) {
			newArray[i] = temp->data;
			temp = temp->next;
		}

		return newArray;
	}

	int size()
	{
		return length;
	}
	void clear()
	{
		if (length == 1) {
			Node* temp;
			temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
		}
		else if (length > 1) {
			Node *temp;
			temp = tail;
			for (int i = 0; i < length - 1; i++) {
				temp = (*temp).prev;
			}

			head = nullptr;
			tail = nullptr;
		}

		length = 0;
	}
};


class BinaryTree {
	struct Node {
		EmployeeInfo data;
		//Node* parent; // don't need it
		Node* left = nullptr;
		Node* right = nullptr;
	};
	bool null;
	Node* head;

public:
	BinaryTree() {
		null = true;
		head = new Node;
	}
	~BinaryTree() {
		clear();
	}

	int compare(EmployeeInfo a, EmployeeInfo b) {
		if (a.getID() == 0) {
			return -1;
		}
		if (a.getID() < b.getID()) {
			return -1;
		}
		if (a.getID() > b.getID()) {
			return 1;
		}
		return 0;
	}

	void insert(EmployeeInfo n) {

		if (null) {
			head->data = n;
			null = false;
			return;
		}

		Node* temp = head;
		while (true) {
			if (compare(n, (*temp).data) == -1) {
				if (temp->left == nullptr) {
					Node* temp2 = new Node;
					temp->left = temp2;
					temp2->data = n;
					break;
				}
				else { // AKA TEMP->LEFT != NULLPTR.
					temp = temp->left;
				}
			}

			else { // n >= temp->data
				if ((*temp).right == nullptr) {
					Node* temp2 = new Node;
					temp->right = temp2;
					temp2->data = n;
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}

	EmployeeInfo search(int ID) {

		cout << "Choo choo" << endl;

		Node* temp = head;
		while (true) {

			if (compare(EmployeeInfo(ID, ""), temp->data) == -1) {
				if (temp->left != nullptr) {
					temp = temp->left;
				}
				else {
					break; // cannot find it
				}
			}

			else if (compare(EmployeeInfo(ID, ""), temp->data) == 1) {
				if (temp->right != nullptr) {
					temp = temp->right;
				}
				else {
					break; // cannot find it
				}
			}

			else { // n == temp->data
				return temp->data;
			}
		}

		return EmployeeInfo();
	}

	void clear() {
		if (!head) {
			return;
		}
		if (head->left != nullptr) {
			clearHelper(head->left);
		}
		if (head->right != nullptr) {
			clearHelper(head->right);
		}

		delete head;
		head = new Node;

		null = true;
	}

	string toString(int n) {
		if (n == 1) { // preorder
			return preorderPrint(head);
		}
		else if (n == 2) {
			return postorderPrint(head);
		}
		else {
			return inorderPrint(head);
		}
	}

	/*string inorderPrint(Node* temp) {
	if (temp != nullptr) {
	return ((temp->left==nullptr)?"":inorderPrint(temp->left)+" ") + to_string(temp->data) + " " + ((temp->right == nullptr) ? "" : inorderPrint(temp->right));
	}
	return "";
	}

	string preorderPrint(Node* temp) {
	if (temp != nullptr) {
	return to_string(temp->data) + " " + ((temp->left == nullptr) ? "" : preorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : preorderPrint(temp->right));
	}return "";
	}

	string postorderPrint(Node* temp) {
	if (temp != nullptr) {
	return ((temp->left == nullptr) ? "" : postorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : postorderPrint(temp->right) + " ") + to_string(temp->data);
	}return "";
	}*/

	void balanceTree() {
		if (head == nullptr) {
			return;
		}

		LinkedList<EmployeeInfo> list = LinkedList<EmployeeInfo>();

		Node* temp = head;
		if (temp->left != nullptr) {
			balanceTreeHelper(temp->left, list);
		}

		list.add(temp->data);

		if (temp->right != nullptr) {
			balanceTreeHelper(temp->right, list);
		}

		clear();

		EmployeeInfo* tempArray = list.toArray();


		insertListInto(0, list.size() - 1, tempArray);

	}

	string toString() {
		return inorderPrint(head);
	}
private:
	void insertListInto(int a, int b, EmployeeInfo*c) {
		insert(*(c + (a + b + 1) / 2));

		if (a == b - 1) {
			insert(c[a]);
		}
		else if (a == b) {
			return;
		}
		else if (a < b) {
			//cout << "Passing in, a = " << a << ", b = " << b << endl;
			//system("pause");
			insertListInto(a, (a + b + 1) / 2 - 1, c);
			insertListInto((a + b + 1) / 2 + 1, b, c);
		}
	}

	void balanceTreeHelper(Node* temp, LinkedList<EmployeeInfo> &list) {
		if (temp->left != nullptr) {
			balanceTreeHelper(temp->left, list);
		}

		list.add(temp->data);

		if (temp->right != nullptr) {
			balanceTreeHelper(temp->right, list);
		}
	}

	void clearHelper(Node* temp) {
		if (temp->right != nullptr) {
			clearHelper(temp->right);
		}
		if (temp->left != nullptr) {
			clearHelper(temp->left);
		}

		delete temp;
	}


	string inorderPrint(Node*temp) {
		if (temp != nullptr) {
			return ((temp->left == nullptr) ? "" : inorderPrint(temp->left) + " ") + temp->data.getName()+"::"+to_string(temp->data.getID()) + " " + ((temp->right == nullptr) ? "" : inorderPrint(temp->right));
		}
		return "";
	}

	string preorderPrint(Node*temp) {
		if (temp != nullptr) {
			return temp->data.getName() + "::" + to_string(temp->data.getID()) + " " + ((temp->left == nullptr) ? "" : preorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : preorderPrint(temp->right));
		}return "";
	}

	string postorderPrint(Node*temp) {
		if (temp != nullptr) {
			return ((temp->left == nullptr) ? "" : postorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : postorderPrint(temp->right) + " ") + temp->data.getName() + "::" + to_string(temp->data.getID());
		}return "";
	}

};