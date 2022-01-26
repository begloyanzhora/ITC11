#include "Node.h"

Node::Node(int data, Node* pNext = nullptr) {
    this -> data = data;
    this -> pNext = pNext;
}