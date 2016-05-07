#pragma once
#include <string>
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
		int data;
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

	int compare(int a, int b) {
		if (a < b) {
			return -1;
		}
		if (a > b) {
			return 1;
		}
		return 0;
	}

	void insert(int n) {

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

	int search(int ID) {

		cout << "Choo choo" << endl;

		Node* temp = head;
		while (true) {

			if (compare(ID, temp->data) == -1) {
				if (temp->left != nullptr) {
					temp = temp->left;
				}
				else {
					break; // cannot find it
				}
			}

			else if (compare(ID, temp->data) == 1) {
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

		return int();
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

	int numNodes() {
		if (head == nullptr) {
			return 0;
		}

		if (head->right != nullptr) {
			if (head->left != nullptr) {
				return 1 + numNodesHelper(head->left) + numNodesHelper(head->right);
			}
			return 1 + numNodesHelper(head->right);
		}

		if (head->left != nullptr) {
			return 1 + numNodesHelper(head->left);
		}

		return 1;
	}

	int numNodesHelper(Node* temp) {
		if (temp->right != nullptr) {
			if (temp->left != nullptr) {
				return 1 + numNodesHelper(temp->left) + numNodesHelper(temp->right);
			}
			return 1 + numNodesHelper(temp->right);
		}

		if (temp->left != nullptr) {
			return 1 + numNodesHelper(temp->left);
		}

		return 1;
	}

	int numLeaves() {
		if (head == NULL) {
			return 0;
		}

		if (head->right != NULL) {
			if (head->left != NULL) {
				return numLeavesHelper(head->left) + numLeavesHelper(head->right);
			}
			return numLeavesHelper(head->right);
		}

		if (head->left != NULL) {
			return numLeavesHelper(head->left);
		}

		return 1;
	}

	int numLeavesHelper(Node* temp) {
		if (temp == nullptr) {
			return 1;
		}
		if (temp->right != NULL) {
			if (temp->left != NULL) {
				return numLeavesHelper(temp->left) + numLeavesHelper(temp->right);
			}
			return numLeavesHelper(temp->right);
		}

		if (head->left != NULL) {
			return numLeavesHelper(temp->left);
		}

		return 1;
	}

	int numLevels() {
		if (head == nullptr) {
			return 0;
		}

		int a = 0, b = 0;
		if (head->left != nullptr) {
			a = numLevelsHelper(head->left);
		}
		if (head->right != nullptr) {
			b = numLevelsHelper(head->right);
		}

		if (a > b) {
			return a ;
		}
		else {
			return b;
		}
	}

	int numLevelsHelper(Node* temp) {
		if (temp == nullptr) {
			return 0;
		}

		int a = 0, b = 0;
		if (temp->left != nullptr) {
			a = numLevelsHelper(temp->left);
		}
		if (temp->right != nullptr) {
			b = numLevelsHelper(temp->right);
		}

		if (a > b) {
			return a + 1;
		}
		else {
			return b + 1;
		}
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

	string visualization() {
		return preorderVisualization(head, 0);
	}

	string preorderVisualization(Node* temp, int n) {
		if (temp == nullptr) {
			return "";
		}
		string s = to_string(temp->data);
		for (int i = 0; i < n; i++) {
			s = "\t" + s;
		}

		s += "\n" + preorderVisualization(temp->left, n + 1);
		s += "\n" + preorderVisualization(temp->right, n + 1);

		return s;
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

		LinkedList<int> list = LinkedList<int>();

		Node* temp = head;
		if (temp->left != nullptr) {
			balanceTreeHelper(temp->left, list);
		}

		list.add(temp->data);

		if (temp->right != nullptr) {
			balanceTreeHelper(temp->right, list);
		}

		clear();

		int* tempArray = list.toArray();


		insertListInto(0, list.size() - 1, tempArray);

	}

	string toString() {
		return inorderPrint(head);
	}
private:
	void insertListInto(int a, int b, int*c) {
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

	void balanceTreeHelper(Node* temp, LinkedList<int> &list) {
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
			return ((temp->left == nullptr) ? "" : inorderPrint(temp->left) + " ") + to_string(temp->data) + " " + ((temp->right == nullptr) ? "" : inorderPrint(temp->right));
		}
		return "";
	}

	string preorderPrint(Node*temp) {
		if (temp != nullptr) {
			return to_string(temp->data) + " " + ((temp->left == nullptr) ? "" : preorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : preorderPrint(temp->right));
		}return "";
	}

	string postorderPrint(Node*temp) {
		if (temp != nullptr) {
			return ((temp->left == nullptr) ? "" : postorderPrint(temp->left) + " ") + ((temp->right == nullptr) ? "" : postorderPrint(temp->right) + " ") + to_string(temp->data);
		}return "";
	}

};