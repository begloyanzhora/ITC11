#include <iostream>
#include "Btree.cpp"

int main () {

	Btree<int> inTtree;
	int treeIntvalues[7] = {1, 2, 3, 4, 5, 6, 7};

	for (int i = 0; i < 7; i++) {
		inTtree.addLeaf(treeIntvalues[i]);
	}

	std::cout << std::endl << std::endl;
	inTtree.levelOrderPrint();
	return 0;
}