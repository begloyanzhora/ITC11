#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

class Queue : protected List {
public:
    void push (int);
    int shift ();
    int getFirst ();
    int getLast ();
    int length ();
};

#endif