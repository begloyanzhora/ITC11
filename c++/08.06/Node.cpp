#include "Node.h"

template<typename T>
Node<T>::Node(T data, Node<T>* pNext) {
    this -> data = data;
    this -> pNext = pNext;
}