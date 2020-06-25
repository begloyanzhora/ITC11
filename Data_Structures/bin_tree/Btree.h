#ifndef BTREE__H
#define BTREE__H

template <typename T>
struct Node {
	T value;
	Node* left;
	Node* right;
};

template <typename T>
class Btree {
private:
	Node<T>* root;
	Node<T>* createLeaf(T);
	void addLeafPrivate(T, Node<T>*);
	void printPrivate(Node<T>*);

public:
	Btree();
	/* ~Btree(); */

	void addLeaf(T);
	void print();
};

#endif