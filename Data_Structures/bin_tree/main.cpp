#include <iostream>
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

	Node<char>* n = tree.getNode('a')->right;
	std::cout << "a->right: " << **n << std::endl;

	int min = inTtree.findMin();
	std::cout << "Min in second tree: " << min << std::endl;

	tree.removeNode('c');
	std::cout << "The trees' elements: " << std::endl;
	tree.print();

	std::cout << std::endl << std::endl;
	inTtree.removeNode(6);
	inTtree.print();

	std::cout << std::endl << std::endl;
	return 0;
}