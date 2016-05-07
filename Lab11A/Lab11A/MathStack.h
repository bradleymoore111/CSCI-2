#pragma once

//template <class T>
class MathStack {

private:
	struct Node {
		Node *next;
		int data;
	};

	Node *head; // When adding stuff, will replace head, and make it point to head. When popping stuff, will take head, then delete it

public:
	MathStack() {
		head = nullptr;
	}
	~MathStack() {
		clear();
	}

	void push(int a) {
		if (isEmpty()) {
			head = new Node;
			(*head).data = a;
			(*head).next = nullptr;
		}
		else {
			Node *temp = new Node;
			(*temp).next = head;
			(*temp).data = a;
			head = temp;
		}
	}

	int pop() {
		if (head == nullptr) {
			throw nullptr;
		}
		else if ((*head).next == nullptr) { // no more pointers after it
			int a = (*head).data;
			delete head;
			head = nullptr;

			return a;
		}
		else {
			int a = (*head).data;
			Node *temp = head;

			head = (*head).next;
			delete temp;

			return a;
		}
	}

	int peek() {
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

	void add() {
		if (isEmpty()) {
			return;
		}

		int a = pop();
		if (isEmpty()) {
			push(a);
			return;
		}
		int b = pop();

		push(a + b);
	}

	void sub() {
		if (isEmpty()) {
			return;
		}

		int a = pop();
		if (isEmpty()) {
			push(a);
			return;
		}
		int b = pop();

		push(b - a);
	}

	void mult() {
		if (isEmpty()) {
			return;
		}

		int a = pop();
		if (isEmpty()) {
			push(0);
			return;
		}
		int b = pop();

		push(a * b);
	}

	void div() {
		if (isEmpty()) {
			return;
		}

		int a = pop();
		if (isEmpty()) {
			push(0);
			return;
		}
		int b = pop();

		if (a == 0) {
			push(0);
		}
		else {
			push(b / a);
		}
	}

	void addAll() {
		int a = 0;
		while (hasNext()) {
			a += pop();
		}

		push(a);
	}

	void multAll() {
		int a = 1;
		while (hasNext()) {
			a *= pop();
		}

		push(a);
	}
};