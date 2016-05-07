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
		Node *temp2 = new Node; // the new node to insert, temp is just a location node
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
			delete temp; // need to clear up memory
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

	int find(T obj) {
		return -1;
	}
	//string toString() {
	//return "";
	//}

	int size()
	{
		return length;
	}
	void clear()
	{
		if (length == 1) {
			delete head;
			delete tail;

			head = nullptr;
			tail = nullptr;
		}
		else if (length > 1) {
			Node *temp;
			temp = tail;
			for (int i = 0; i < length - 1; i++) {
				temp = (*temp).prev;
				delete (*temp).next;
			}

			delete temp;

			head = nullptr;
			tail = nullptr;
		}

		length = 0;
	}
};

template <>
int LinkedList<int>::find(int a) {
	Node *temp;
	temp = head;
	for (int i = 0; i < length; i++) {
		if ((*temp).data == a) {
			return i;
		}
		temp = (*temp).next;
	}
	return -1;
};

template <>
int LinkedList<double>::find(double a) {
	Node *temp;
	temp = head;
	for (int i = 0; i < length; i++) {
		if ((*temp).data == a) {
			return i;
		}
		temp = (*temp).next;
	}
	return -1;
};

template <>
int LinkedList<string>::find(string a) {
	Node *temp;
	temp = head;
	for (int i = 0; i < length; i++) {
		if ((*temp).data.compare(a) == 0) {
			return i;
		}
		temp = (*temp).next;
	}
	return -1;
};