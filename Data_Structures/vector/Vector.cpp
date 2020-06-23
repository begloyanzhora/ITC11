#include <iostream>
#include "Vector.h"
using namespace std;

template<typename T>
Vector<T>::Vector() {
	rsize = 0;
	maxSize = 20;
	arr = new T[maxSize];
}

template<typename T>
Vector<T>::Vector(unsigned int n) {
	rsize = 0;
	maxSize = n;
	arr = new T[maxSize];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& vec) {
	maxSize = vec.maxSize;
	rsize = vec.rsize;
	arr = new T[maxSize];

	for(int i = 0; i < rsize; ++i) {
		arr[i] = vec.arr[i];
	}
}

template<typename T>
void Vector<T>::pushBack(T elem) {
	if (rsize + 1 > maxSize) {
		alloc();
	}

	arr[rsize] = elem;
	++rsize;
}

template<typename T>
unsigned int Vector<T>::size() {
	return rsize;
}

template<typename T>
unsigned int Vector<T>::capacity() {
	return maxSize;
}

template<typename T>
bool Vector<T>::isEmpty() {
	return (0 == rsize);
}

template<typename T>
T Vector<T>::operator[](unsigned int i) {
	return arr[i];
}
/*------------------------------Doesn't work--------------------------------*/
/* template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
	if (this != &Vector) {
		maxSize = v.maxSize;
		rsize = v.rsize;
		delete[] arr;
		arr = new T[maxSize];

		for (int i = 0; i < rsize; ++i) {
			arr[i] = v.arr[i];
		}
	}
	return *this;
} */
/*----------------------------------------------------------------------------*/
template<typename T>
T Vector<T>::at(unsigned int i) {
	if (i < rsize) {
		return arr[i];
	}
	try {
		throw "Please run again and enter the valid index.";
	} catch(const char* e) {
		cout << e << endl;
	}
}

template<typename T>
void Vector<T>::resize(unsigned int n) {
	maxSize = n;
	T* tmp = new T[maxSize];

	for(int i = 0; i < maxSize; ++i) {
		tmp[i] = arr[i];
	}

	delete[] arr;

	arr = tmp;
}

template<typename T>
void Vector<T>::shrinkToFit() {
	resize(rsize);
}

template<typename T>
void Vector<T>::alloc() {
	unsigned int n = rsize * 2;
	resize(n);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
	return Vector<T>::Iterator(&arr[0]);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end() {
	return Vector<T>::Iterator(rsize);
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
}