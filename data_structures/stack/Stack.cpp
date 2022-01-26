#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
	sTop = NULL;
    length = 0;
}

template <typename T>
Stack<T>::Stack(T elem, unsigned int n) {
	while (n != 0) {
        push(elem);
        --n;
    }
}

template <typename T>
Stack<T>::~Stack() {
	while (!isEmpty()) {
		pop();
	}
}

template <typename T>
void Stack<T>::push(T elem) {
	Node<T>* temp = new Node<T>;
	temp->data = elem;
	temp->prev = sTop;
	sTop = temp;
    ++length;
}

template <typename T>
void Stack<T>::pop() {
	if (!isEmpty()) {
		Node<T>* oldTop = sTop;
		sTop = oldTop->prev;
		delete oldTop;
        --length;
	} else {
		std::cout << "The stack is empty!!!!" << std::endl;
		exit(1);
	}
}

template <typename T>
T Stack<T>::top() {
	if (!isEmpty()) {
		T data = sTop->data;
		return data;
	}
}

template <typename T>
bool Stack<T>::isEmpty() {
	return (sTop == NULL);
}

template <typename T>
unsigned int Stack<T>::size() {
    return length;
}