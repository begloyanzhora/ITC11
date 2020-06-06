#include "Queue.h"
#include <iostream>

void Queue::push (int elem) {
    int index = length ();
    insert (elem, index);
}

int Queue::shift () {
    int elem = getFirst();
    remove (0);
    return elem;
}

int Queue::getFirst () {
    return getElemByIndex(0);
}

int Queue::getLast () {
    return getElemByIndex(length() - 1);
}

int Queue::length () {
    return getLength();
}

Queue::~Queue () {
    clear();
}