#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	int length;

public:
	List();
	~List();

	int getLength();
	T getElemByIndex(int);
	void show ();
	void push(T);
	void unshift(T);
	void remove(int);
	void clear ();

	class Iterator;
	Iterator begin();
	Iterator end();
	void insert (T, List<T>::Iterator);
};

#endif