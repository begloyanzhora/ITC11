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
    int n = 0;

    std::cout << "Please enter the integer number => 0: ";
    std::cin >> n;

    while (std::cin.fail() || n < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please reenter the valid number: ";
        std::cin >> n;
    }

    std::cout << "Calculate with recursion: " << factWithRec (n) << std::endl;
    std::cout << "Calculate with loop: " << factWithLoop (n) << std::endl;

    return 0;
}