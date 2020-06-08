#include "List.h"
//#include "Queue.h"
#include <iostream>

int main () {
    List<int> l;

    l.insert(45, 0);
    l.insert(15., 1);
    l.insert(45, 2);

    std::cout << l.getElemByIndex(0);
    //l.show();
    return 0;
}