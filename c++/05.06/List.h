#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
    Node* head;
    int length;

public:
    List();
    ~List();
    int getLength();
    int getElemByIndex(int);
    void show ();
    void insert (int, int);
    void remove(int);
    void clear ();
};

#endif