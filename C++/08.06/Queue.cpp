#include "Queue.h"
#include <iostream>

template<typename T>
void Queue<T>::push (T elem) {
    int index = length ();
    this->insert (elem, index);
}

template<typename T>
T Queue<T>::shift () {
    T elem = getFirst();
    this->remove (0);
    return elem;
}

template<typename T>
T Queue<T>::getFirst () {
    return this->getElemByIndex(0);
}

template<typename T>
T Queue<T>::getLast () {
    return this->getElemByIndex(length() - 1);
}

template<typename T>
int Queue<T>::length () {
    return this->getLength();
}

template<typename T>
Queue<T>::~Queue () {
    this->clear();
}