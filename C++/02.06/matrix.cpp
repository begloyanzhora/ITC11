#include <iostream>

void print (int **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int **initMatrix (int n, int m) {
    std::cout << "Enter matrix: " << std::endl;

    int **A = new int *[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[m];

        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

    return A;
}

int main () {
    int n = 0;
    int m = 0;

    int x = 0;
    int y = 0;

    std::cout << "Enter rows of matrix A: ";
    std::cin >> n;
    std::cout << "Enter coloums of matrix A: ";
    std::cin >> m;

    std::cout << "Enter rows of matrix B: ";
    std::cin >> x;
    std::cout << "Enter coloums of matrix B: ";
    std::cin >> y;

    int **a = initMatrix(n, m);
    int **b = initMatrix(x, y);

    print(a, n, m);
    print(b, x, y);
}