#include "Queue.h"
#include <iostream>

template<typename T>
void Queue<T>::push (T elem) {
    int index = length ();
    insert (elem, index);
}

template<typename T>
T Queue<T>::shift () {
    int elem = getFirst();
    remove (0);
    return elem;
}

template<typename T>
T Queue<T>::getFirst () {
    return getElemByIndex(0);
}

template<typename T>
T Queue<T>::getLast () {
    return getElemByIndex(length() - 1);
}

template<typename T>
int Queue<T>::length () {
    return getLength();
}

template<typename T>
Queue<T>::~Queue () {
    clear();
}