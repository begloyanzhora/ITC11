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

	void addLeafPrivate(T, Node<T>*);

public:
	Btree();
	~Btree();

	Node<T>* createLeaf(T);
	void addLeaf(T);
};

#endif