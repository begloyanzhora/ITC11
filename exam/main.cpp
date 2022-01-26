#include <iostream>
#include "Btree.cpp"

int main () {

	Btree<int> inTtree;
	int treeIntvalues[7] = {3, 5, 6, 8, 10, 12, 14};

	for (int i = 0; i < 7; i++) {
		inTtree.addLeaf(treeIntvalues[i]);
	}

	std::cout << std::endl << std::endl;
	inTtree.levelOrderPrint();

	std::cout << "Min absolute difference betwwen root and leaeves: " << inTtree.getMinAbsolDiff() << std::endl;
	return 0;
}