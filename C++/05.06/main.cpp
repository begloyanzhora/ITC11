#include "List.h"
#include "Queue.h"
#include <iostream>

int main () {
    Queue q;

    q.push(45);
    q.push(15);
    q.push(24);

    std::cout << "First: " << q.getFirst() << std::endl;
    std::cout << "Last: " << q.getLast() << std::endl;
    std::cout << "Removed: " << q.shift() << std::endl;
    std::cout << "Length: " << q.length() << std::endl;

    return 0;
}