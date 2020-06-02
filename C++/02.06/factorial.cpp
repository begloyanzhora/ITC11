#include <iostream>

int factWithRec (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factWithRec(n - 1);
}

int factWithLoop (int n) {
    int res = 1;

    for (int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}

int main () {
    int n = 4;

    std::cout << factWithRec (n) << std::endl;
    std::cout << factWithLoop (n) << std::endl;

    return 0;
}