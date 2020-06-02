#include <iostream>

int main () {
    int n;

    do {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while (n < 2);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (n * 2 - (2 * i -1)); j++) {
            if (i == 1 || j == 1 || j == (n * 2 - (2 * i - 1) )) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }

    return 0;
}