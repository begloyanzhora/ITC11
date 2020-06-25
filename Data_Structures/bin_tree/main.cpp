#include <iostream>
#include <cstdlib>
#include "Btree.cpp"

int main () {
	Btree<char> tree;
	char treevalues[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	Btree<int> inTtree;
	int treeIntvalues[7] = {4, 2, 1, 3, 6, 5, 7};

	for (int i = 0; i < 7; i++) {
		tree.addLeaf(treevalues[i]);
	}

	for (int i = 0; i < 7; i++) {
		inTtree.addLeaf(treeIntvalues[i]);
	}

	std::cout << "The tree's elements: " << std::endl;
	tree.print();
	std::cout << std::endl << std::endl;

	inTtree.print();
	return 0;
}