#pragma once

template <class T>
class StaticStack {

private:
	T *stuff;
	int curr;
	int size;
public:
	StaticStack<T>(int n) {
		size = n;
		stuff = new T[size];
		curr = -1;
	}
	~StaticStack<T>() {
		clear();
	}

	void push(T a) {
		if (isFull()) {
			throw a;
		}
		else {
			curr++;
			stuff[curr] = a;
		}
	}

	T pop() {
		if (isEmpty()) {
			throw nullptr;
		}
		else {
			curr--;
			return stuff[curr + 1];
		}
	}

	T peek() {
		if (isEmpty()) {
			throw nullptr;
		}
		else {
			return stuff[curr];
		}
	}

	void clear() {
		delete stuff;
		stuff = new T[size];
		curr = 0;
	}

	bool isFull() {
		return curr == size-1;
	}

	bool isEmpty() {
		return curr == -1;
	}
};