#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
	Node* pNext;
	Node* pPrev;
	T data;

	Node(T data, Node* pPrev = nullptr, Node* pNext = nullptr) {
		this->data = data;
		this->pPrev = pPrev;
		this->pNext = pNext;
	}
};

#endif