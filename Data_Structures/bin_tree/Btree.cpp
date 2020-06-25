#include "Btree.h"
#include <iostream>

template <typename T>
Btree<T>::Btree() {
	root = nullptr;
}

template <typename T>
Node<T>* Btree<T>::createLeaf(T value) {
	Node<T>* n = new Node<T>;
	n->value = value;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}

template <typename T>
void Btree<T>::addLeafPrivate(T value, Node<T>* ptr) {

	if (root == nullptr) {
		root = createLeaf(value);

	} else if (value < ptr->value) {

		if (ptr->left != nullptr) {
			addLeafPrivate (value, ptr->left);

		} else {
			ptr->left = createLeaf(value);
		}

	} else if (value > ptr->value) {

		if (ptr->right != nullptr) {
			addLeafPrivate (value, ptr->right);

		} else {
			ptr->right = createLeaf(value);
		}

	} else {
		std::cout << "This value already added." << std::endl;

	}
}

template <typename T>
void Btree<T>::addLeaf(T value) {
	addLeafPrivate(value, root);
}

template <typename T>
void Btree<T>::printPrivate(Node<T>* ptr) {

	if (root != nullptr) {

		if (ptr->left != nullptr) {
			printPrivate(ptr->left);
		}
		std::cout << ptr->value << "\t";

		if (ptr->right != nullptr) {
			printPrivate(ptr->right);
		}

	} else {
		std::cout << "The tree is empty." << std::endl;
	}
}

template <typename T>
void Btree<T>::print() {
	printPrivate(root);
}