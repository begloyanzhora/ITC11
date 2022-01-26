#include "List.h"
#include <iostream>

int main () {

    List test;
    test.insert(65, 0);
    test.insert(66, 1);
    test.insert(67, 2);
    test.insert(68, 3);

    test.remove(0);

    test.show();

    std::cout << "Element by index 0: " << test.getElemByIndex(0) << std::endl;
    std::cout << "Length: " << test.getLength() << std::endl;

    return 0;
}