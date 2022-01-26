#include "List.h"
#include "List.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include <iostream>

int main () {
    List<double> l1;
    List<int> l2;

    l1.insert(45.5, 0);
    l1.insert(15.4, 1);
    l1.insert(45.8, 2);

    l2.insert(45.5, 0);
    l2.insert(15.4, 1);
    l2.insert(45.8, 2);

    l1.show();
    std::cout << std::endl;
    l2.show();

    Queue<double> q;

    q.push(1.5);
    q.push(4.5);
    q.push(2.4);

    std::cout << "First: " << q.getFirst() << std::endl;
    std::cout << "Last: " << q.getLast() << std::endl;
    std::cout << "Removed: " << q.shift() << std::endl;
    std::cout << "Length: " << q.length() << std::endl;

    return 0;
}