#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	BinaryTree a;
	BinaryTree b;

	for (int i = 0; i < 20; i++) {
		a.insert(i + 1);
	}

	for (int i = 0; i < 10; i++) {
		b.insert(rand() % 20 + 1);
	}

	cout << "Nums 1-20 pre-balanced:\n" << a.visualization() << "\n\tNodes: " << a.numNodes() << "\n\tLeaves: " << a.numLeaves() << "\n\tHeight: " << a.numLevels() << endl;
	cout << "Nums 1-10 randomized pre-balanced:\n" << b.visualization() << "\n\tNodes: " << b.numNodes() << "\n\tLeaves: " << b.numLeaves() << "\n\tHeight: " << b.numLevels() << endl;

	a.balanceTree();
	b.balanceTree();

	cout << "Nums 1-20 post-balanced:\n" << a.visualization() << "\n\tNodes: " << a.numNodes() << "\n\tLeaves: " << a.numLeaves() << "\n\tHeight: " << a.numLevels() << endl;
	cout << "Nums 1-10 randomized post-balanced:\n" << b.visualization() << "\n\tNodes: " << b.numNodes() << "\n\tLeaves: " << b.numLeaves() << "\n\tHeight: " << b.numLevels() << endl;
	return 0;
}