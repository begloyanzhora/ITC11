#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node* pNext;
    T data;

    Node(T, Node*);
};

#endif