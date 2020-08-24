#include <iostream>
#include "List.h"

List::List () {
    length = 0;
    head = nullptr;
}

int List::getLength () {
    return length;
}

int List::getElemByIndex (int index) {
    int count = 0;
    Node* current = this -> head;

    while (current != nullptr) {
        if (count == index) {
            return current -> data;
        }
        current = current -> pNext;
        count++;
    }
}

void List::show () {
    std::cout << "List: ";

    for (int i = 0; i < length; i++) {
        std::cout << getElemByIndex(i) << '\t';
    }
}

void List::insert (int data, int index) {
    if (index == 0) {
        head = new Node(data, head);
    } else {
        Node* prev = this -> head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev -> pNext;
        }

        Node* newNode = new Node (data, prev -> pNext);
        prev -> pNext = newNode;
    }
    length++;
}

void List::remove (int index) {
    if(index == 0) {
        Node* temp = head;
        head = head -> pNext;

        delete temp;
    } else {
        Node* prev = this -> head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev -> pNext;
        }

        Node *forRemove = prev -> pNext;
        prev -> pNext = forRemove -> pNext;
    }
    length--;
}

List::~List () {
    while (length){
        Node* temp = head;
        head = head -> pNext;

        delete temp;
        length--;
    }
}