#include <iostream>
#include "List.h"

template <typename T>
List<T>::List () {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
int List<T>::getLength () {
	return length;
}


template <typename T>
T List<T>::getElemByIndex (int index) {
	int count = 0;
	Node<T>* current = this -> head;

	while (current != nullptr) {
		if (count == index) {
			return current -> data;
		}
		current = current -> pNext;
		count++;
	}
}


template <typename T>
void List<T>::show () {
	std::cout << "List: ";

	for (int i = 0; i < length; i++) {
		std::cout << getElemByIndex(i) << ' ';
	}
}

template <typename T>
void List<T>::insert (T data, List<T>::Iterator i) {
	Node<T>* prev = i;

	Node<T>* newNode = new Node<T>(data);
	newNode->pPrev = prev;
	newNode->pNext = prev->pNext;

	newNode->pNext = prev->pNext;
	prev->pNext = newNode;

	length++;
}

template <typename T>
void List<T>::remove (int index) {
	if(index == 0) {
		Node<T>* temp = head;
		head = head -> pNext;

		delete temp;
	} else {
		Node<T>* prev = this -> head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev -> pNext;
		}

		Node<T> *forRemove = prev -> pNext;
		prev -> pNext = forRemove -> pNext;
		delete forRemove;
	}
	length--;
}

template <typename T>
void List<T>::push (T elem) {
	Node<T>* newNode = new Node<T>(elem);

	if (head == nullptr) {
		head = newNode;
		tail = head;

	} else {
		tail->pNext = newNode;
		newNode->pPrev = tail;
		tail = newNode;

	}
	++length;
}

template <typename T>
void List<T>::unshift (T elem) {
	Node<T>* newNode = new Node<T>(elem);

	if (head == nullptr) {
		head = newNode;
		tail = head;

	} else {
		head->pPrev = newNode;
		newNode->pNext = head;
		head = newNode;

	}
	++length;
}

template <typename T>
void List<T>::clear () {
	while (length){
	Node<T>* temp = head;
	head = head -> pNext;

	delete temp;
	length--;
	}
}

template<typename T>
typename List<T>::Iterator List<T>::begin() {
	return List<T>::Iterator(this->head);
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
	return List<T>::Iterator(this->tail);
}

template <typename T>
List<T>::~List () {
	clear();
}