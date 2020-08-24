#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node {
	T data;
	Node* prev;
};

template <typename T>
class Stack {
private:
	Node<T>* sTop;
	unsigned int length;

public:
	Stack();
	Stack(T, unsigned int);
	~Stack();

	bool isEmpty();
	void push(T);
	void pop();
	T top();
	unsigned int size();
};

#endif