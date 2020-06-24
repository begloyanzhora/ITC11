#include "List.h"
#include "List.cpp"
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
    l2.show();

    return 0;
}