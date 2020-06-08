#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Node.cpp"

template <typename T>
class List {
private:
    Node<T>* head;
    int length;

public:
    List();
    ~List();
    int getLength();
    T getElemByIndex(int);
    void show ();
    void insert (T, int);
    void remove(int);
    void clear ();
};

#endif