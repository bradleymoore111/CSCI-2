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

	int getPosOf(int);
	void clear();
	int size();
	string toString();
};

