/*
*	Homework assignment 10, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once

template <class T>
class Stack {

private:
	struct Node {
		Node *next;
		T data;
	};

	Node *head; // When adding stuff, will replace head, and make it point to head. When popping stuff, will take head, then delete it

public:
	Stack<T>() {
		head = nullptr;
	}
	~Stack<T>() {
		clear();
	}

	void push(T a) {
		if (isEmpty()) {
			head = new Node;
			head->data = a;
			head->next = nullptr;
		}
		else {
			Node *temp = new Node;
			(*temp).next = head;
			(*temp).data = a;
			head = temp;
		}
	}

	T pop() {
		if (head == nullptr) {
			throw nullptr;
		}
		else if ((*head).next == nullptr) { // no more pointers after it
			T a = (*head).data;
			delete head;
			head = nullptr;

			return a;
		}
		else {
			T a = (*head).data;
			Node *temp = head;

			head = (*head).next;
			delete temp;

			return a;
		}
	}

	T peek() {
		if (head != nullptr) {
			return (*head).data;
		}
		else {
			throw nullptr;
		}
	}

	void clear() {
		if (head == nullptr) {
			return;
		}
		while ((*head).next != nullptr) {
			Node *temp = head;
			head = (*head).next;

			delete temp;
		}
		if (head != nullptr) {
			delete head;
			head = nullptr;
		}
	}

	bool hasNext() {
		return head != nullptr;
	}

	bool isEmpty() {
		return head == nullptr;
	}
};