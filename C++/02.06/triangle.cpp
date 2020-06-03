#include <iostream>

int main () {
    int n = 0;

    std::cout << "Please enter the integer number => 2: ";
    std::cin >> n;

    while (std::cin.fail() || n < 2) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please reenter the valid number: ";
        std::cin >> n;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (n * 2 - (2 * i -1)); j++) {
            if (i == 1 || j == 1 || j == (n * 2 - (2 * i - 1))) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }

    return 0;
}