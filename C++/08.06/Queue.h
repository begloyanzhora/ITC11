#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template<typename T>
class Queue : protected List<T> {
public:
    Queue() : List<T>() {}
    ~Queue();
    void push (T);
    T shift ();
    T getFirst ();
    T getLast ();
    int length ();
};

#endif