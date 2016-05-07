/*
*	Homework assignment 8, by Bradley Moore, in CSCI-2-0118
*	Email: bradleym007@gmail.com
*	Phone: 310-906-6659
*	Github: github.com/trashy111
*/

#pragma once
#include <string>

using namespace std;

class LinkedList
{

private:
	struct Node {
		int data;
		Node *next;
		Node *prev;
	};

	Node *head;
	Node *tail;

	int length;

public:
	LinkedList();
	~LinkedList();

	void addItem(int); // input is data to add
	void insItem(int, int);
	int getItem(int); // input is location
	int delItem(int); // input is location
	int setItem(int, int); // input is location

	void clear();
	void reverse();

	int size();

	string toString();
};

