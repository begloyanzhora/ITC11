#ifndef ITERATOR_H
#define ITERATOR_H

#include "Vector.h"

template<typename T>
class Vector<T>::Iterator {
private:
	T* ptr;
public:
	Iterator(T*);
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
Vector<T>::Iterator::Iterator(T* i) {
	ptr = i;
}

template<typename T>
T& Vector<T>::Iterator::operator* () {
	return *ptr;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++ () {
	++ptr;
	return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator-- () {
	--ptr;
	return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++ (int) {
	Vector<T>::Iterator tmp = *this;
	++(*this);
	return tmp;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator-- (int) {
	Vector<T>::Iterator tmp = *this;
	--(*this);
	return tmp;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator+ (int n) {
	ptr += n;
	return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator- (int n) {
	ptr -= n;
	return *this;
}

template<typename T>
bool Vector<T>::Iterator::operator== (Iterator& e) {
	return *ptr == *e.ptr;
}

template<typename T>
bool Vector<T>::Iterator::operator!= (Iterator& ne) {
	return *ptr == *ne.ptr;
}


template<typename T>
Vector<T>::Iterator::~Iterator() {

}


#endif