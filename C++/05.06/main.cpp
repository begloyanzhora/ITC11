#include "List.h"
#include <iostream>

int main () {
    List l;

    l.insert(45, 0);
    l.insert(15, 1);
    l.insert(24, 2);

    l.show();

    return 0;
}