#ifndef ITERATOR_H
#define ITERATOR_H

#include "List.h"

template<typename T>
class List<T>::Iterator {
private:
	Node<T>* ptr;
public:
	Iterator(Node<T>*);
	~Iterator();

	T& operator* ();

	Iterator& operator++ ();
	Iterator& operator-- ();

	Iterator& operator++ (int);
	Iterator& operator-- (int);

	Iterator& operator+ (int);
	Iterator& operator- (int);

	bool operator== (Iterator&);
	bool operator!= (Iterator&);
};

template<typename T>
List<T>::Iterator::Iterator(Node<T>* i) {
	ptr = i;
}

template<typename T>
T& List<T>::Iterator::operator* () {
	return ptr->data;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++ () {
	ptr = ptr->pNext;
	return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator-- () {
	ptr = ptr->pPrev;
	return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++ (int) {
	List<T>::Iterator tmp = *this;
	++(*this);
	return tmp;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator-- (int) {
	List<T>::Iterator tmp = *this;
	--(*this);
	return tmp;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator+ (int n) {
	for (int i = 0; i < n; i++) {
		++ptr;
	}
	return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator- (int n) {
	for (int i = 0; i < n; i++) {
		--ptr;
	}
	return *this;
}

template<typename T>
bool List<T>::Iterator::operator== (Iterator& e) {
	return *ptr == *e.ptr;
}

template<typename T>
bool List<T>::Iterator::operator!= (Iterator& ne) {
	return *ptr == *ne.ptr;
}


template<typename T>
List<T>::Iterator::~Iterator() {

}


#endif