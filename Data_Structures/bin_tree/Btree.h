#ifndef BTREE__H
#define BTREE__H

template <typename T>
struct Node {
	T value;
	Node* left;
	Node* right;
	T& operator* () {
		return value;
	}
};

template <typename T>
class Btree {
private:
	Node<T>* root;
	Node<T>* createLeaf(T);
	void addLeafPrivate(T, Node<T>*);
	void printPrivate(Node<T>*);
	Node<T>* getNodePrivate(T, Node<T>*);
	T findMinPrivate(Node<T>*);
	void removeRoot();
	void removeMatch(Node<T>*, Node<T>*, bool);
	void removeNodePrivate(T, Node<T>*);
	void removeSubTree(Node<T>*);

public:
	Btree();
	~Btree();

	void addLeaf(T);
	void print();
	Node<T>* getNode(T);
	T findMin();
	void removeNode(T);
};

#endif