#include <iostream>
#include "List.h"

template <typename T>
List<T>::List () {
    length = 0;
    head = NULL;
    tail = NULL;
}

template <typename T>
int List<T>::getLength () {
    return length;
}


template <typename T>
T List<T>::getElemByIndex (int index) {
    int count = 0;
    Node<T>* current = this -> head;

    while (current != nullptr) {
        if (count == index) {
            return current -> data;
        }
        current = current -> pNext;
        count++;
    }
}


template <typename T>
void List<T>::show () {
    std::cout << "List: ";

    for (int i = 0; i < length; i++) {
        std::cout << getElemByIndex(i) << '\t';
    }
}

template <typename T>
void List<T>::insert (T data, int index) {
    if (index == 0) {
        head = new Node<T>(data);
        tail = head;
    } else {
        Node<T>* prev = this -> head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev -> pNext;
        }
        Node<T>* next = prev->pNext;

        Node<T>* newNode = new Node<T> (data, prev, next);
        prev->pNext = newNode;
        next->pPrev = newNode;
    }
    length++;
}

template <typename T>
void List<T>::remove (int index) {
    if(index == 0) {
        Node<T>* temp = head;
        head = head -> pNext;

        delete temp;
    } else {
        Node<T>* prev = this -> head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev -> pNext;
        }

        Node<T> *forRemove = prev -> pNext;
        prev -> pNext = forRemove -> pNext;
        delete forRemove;
    }
    length--;
}

template <typename T>
void List<T>::clear () {
    while (length){
    Node<T>* temp = head;
    head = head -> pNext;

    delete temp;
    length--;
    }
}

template <typename T>
List<T>::~List () {
    clear();
}