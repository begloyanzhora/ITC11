#include "queue"
#include "Btree.h"
#include <iostream>

int max(int a, int b) {
	return a > b ? a : b;
}

template <typename T>
Btree<T>::Btree() {
	root = nullptr;
}

template <typename T>
int Btree<T>::height(Node<T>* tree) {
	return tree == nullptr ? 0 : tree->height;
}

template <typename T>
Node<T>* Btree<T>::createLeaf(T value) {
	Node<T>* n = new Node<T>;
	n->value = value;
	n->left = nullptr;
	n->right = nullptr;
	n->parent = nullptr;
	n->height = 1;

	return n;
}


template <typename T>
Node<T>* Btree<T>::leftBalance(Node<T>* node) {
	Node<T>* r = node->left;
	node->left = r->right;
	r->right = node;
	node->height = max( height(node->right), height(node->left) ) + 1;
	r->height = max( height(r->left), height(node) ) + 1;
	return r;
}

template <typename T>
Node<T>* Btree<T>::rightBalance(Node<T>* node) {
	Node<T>* r = node->right;
	node->right = r->left;
	r->left = node;
	node->height = max( height(node->right), height(node->left) ) + 1;
	r->height = max( height(r->right), height(node) ) + 1;
	return r;
}

template <typename T>
Node<T>* Btree<T>::doubleBalanceLeft(Node<T>* node) {
	node->left = rightBalance(node->left);
	return leftBalance(node);
}

template <typename T>
Node<T>* Btree<T>::doubleBalanceRight(Node<T>* node) {
	node->right = leftBalance(node->right);
	return rightBalance(node);
}

template <typename T>
Node<T>* Btree<T>::addLeafPrivate(T value, Node<T>* ptr) {
	Node<T>* leaf = createLeaf(value);
	if (root == nullptr) {
		root = leaf;
		return root;

	} else if (value < ptr->value) {

		if(ptr->left != nullptr) {
			ptr->left = addLeafPrivate(value, ptr->left);
		} else {
			ptr->left = leaf;
		}

		if(height(ptr->left) - height(ptr->right) == 2) {
			if(value < ptr->left->value) {
				ptr = leftBalance(ptr);
			}else{
				ptr = doubleBalanceLeft(ptr);
			}
		}

	} else if (value > ptr->value) {

		if(ptr->right != nullptr) {
			ptr->right = addLeafPrivate(value, ptr->right);
		} else {
			ptr->right = leaf;
		}

		if(height(ptr->right) - height(ptr->left) == 2) {
			if(value > ptr->right->value) {
				ptr = rightBalance(ptr);
			}else{
				ptr = doubleBalanceRight(ptr);
			}
		}
	} else {
		std::cout << "This value already added." << std::endl;
	}

	ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
	return ptr;
}

template <typename T>
void Btree<T>::addLeaf(T value) {
	root = addLeafPrivate(value, root);
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

template <typename T>
void Btree<T>::levelOrderPrint() {

	if (NULL != root) {

		std::queue<Node<T>*> queue;
		queue.push(root);

		while (!queue.empty()) {
			Node<T>* node = queue.front();
			std::cout << node->value << " ";
			queue.pop();

			if (node->left) {
				queue.push(node->left);
			}

			if (node->right) {
				queue.push(node->right);
			}
		}

		std::cout << std::endl;
	}
}

template <typename T>
Node<T>* Btree<T>::getNodePrivate(T value,  Node<T>* ptr){
	if (ptr != nullptr) {

		if (ptr->value == value) {
			return ptr;

		} else {

			if (value < ptr->value) {
				return getNodePrivate(value, ptr->left);

			} else {
				return getNodePrivate(value, ptr->right);

			}

		}
	} else {
		return nullptr;
	}


}

template <typename T>
Node<T>* Btree<T>::getNode(T value){
	return getNodePrivate(value, root);
}

template <typename T>
T Btree<T>::findMinPrivate(Node<T>* ptr) {
	if (root == nullptr) {
		std::cout << "The tree is empty" << std::endl;
		return T();

	} else {

		if (ptr->left != nullptr) {
			return findMinPrivate(ptr->left);

		} else {
			return ptr->value;

		}
	}

}

template <typename T>
T Btree<T>::findMin() {
	return findMinPrivate(root);
}

template <typename T>
void Btree<T>::removeRoot() {
	if (root != nullptr){
		Node<T>* delPtr = root;
		T minInRighTree;

		if (root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			delete delPtr;

		} else if (root->left == nullptr && root->right != nullptr) {
			root = root->right;
			delPtr->right = nullptr;
			delete delPtr;

		} else if (root->left != nullptr && root->right == nullptr) {
			root = root->left;
			delPtr->left = nullptr;
			delete delPtr;

		} else {
			minInRighTree = findMinPrivate(root->right);
			removeNodePrivate(minInRighTree, root);
			root->value = minInRighTree;

		}
	} else {
		std::cout << "The tree is empty." << std::endl;
	}
}

template <typename T>
void Btree<T>::removeMatch(Node<T>* parent, Node<T>* match, bool left) {
	if (root != nullptr) {
		Node<T>* delPtr;
		T minInRighTree;

		if (match->left == nullptr && match->right == nullptr) {
			delPtr = match;
			left == true ? parent->left = nullptr : parent->right = nullptr;
			delete delPtr;

		} else if (match->left == nullptr && match->right != nullptr) {
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right =nullptr;
			delPtr = match;
			delete delPtr;

		} else if (match->left != nullptr && match->right == nullptr) {
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left =nullptr;
			delPtr = match;
			delete delPtr;

		} else {
			minInRighTree = findMinPrivate(match->right);
			removeNodePrivate(minInRighTree, match);
			match->value = minInRighTree;

		}
	} else {
		std::cout << "The tree is empty." << std::endl;

	}

}

template <typename T>
void Btree<T>::removeNodePrivate(T value, Node<T>* parent) {
	if (root != nullptr) {

		if (root->value == value) {
			removeRoot();

		} else {

			if(value < parent->value){
				parent->left->value == value ? removeMatch(parent, parent->left, true) :
					removeNodePrivate(value, parent->left);

			} else if(value > parent->value){
				parent->right->value == value ? removeMatch(parent, parent->right, false) :
					removeNodePrivate(value, parent->right);

			} else {
				std::cout << "The value wasn't found." << std::endl;

			}

		}
	} else {
		std::cout << "The tree is empty." << std::endl;
	}
}

template <typename T>
void Btree<T>::removeNode(T value) {
	removeNodePrivate(value, root);
}

template <typename T>
void Btree<T>::removeSubTree(Node<T>* ptr) {
	if (ptr != nullptr) {

		if (ptr->left != nullptr) {
			removeSubTree(ptr->left);

		}
		if (ptr->right != nullptr) {
			removeSubTree(ptr->right);

		}
		delete ptr;
	}
}

template <typename T>
Btree<T>::~Btree() {
	removeSubTree(root);
}