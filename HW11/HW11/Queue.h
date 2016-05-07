/*
*	Homework assignment 11, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#include <string>
#include <iostream>

using namespace std;

template<class T>
class Queue
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
	Queue<T>()
	{
		head = nullptr;
		tail = nullptr;

		length = 0;
	}
	~Queue<T>()
	{
		clear();
	}

	void push(T a)
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

	T peek() {
		if (head != nullptr) {
			return head->data;
		}
		else {
			throw nullptr;
		}
	}

	T pop()
	{
		if (length == 0) {
			throw 0;
		}
		T data = (*head).data;

		if ((*head).next == nullptr) {
			head = nullptr;
		}
		else {
			head = (*head).next;
		}

		length--;

		return data;
	} // input is location

	int size()
	{
		return length;
	}
	bool isEmpty() {
		return length == 0;
	}
	bool hasNext() {
		return length >= 1;
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