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

int **mulByConst (int **a, int n, int m, int numb) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] *= numb;
        }
    }
    return a;
}

int **getSum (int **a, int **b, int n, int m, int x, int y) {

    int **sum = new int *[n];

    for (int i = 0; i < n; ++i){
        sum[i] = new int [m];
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    return sum;
}

int main () {
    int n = 0;
    int m = 0;

    int x = 0;
    int y = 0;

    int numb = 0;

    std::cout << "Enter rows of matrix A: ";
    std::cin >> n;
    std::cout << "Enter coloums of matrix A: ";
    std::cin >> m;

    std::cout << "Enter rows of matrix B: ";
    std::cin >> x;
    std::cout << "Enter coloums of matrix B: ";
    std::cin >> y;

    std::cout << "Please enter the number to multiply: ";
    std::cin >> numb;

    int **a = initMatrix(n, m);
    int **b = initMatrix(x, y);
    int **sum = getSum(a, b, n, m, x, y);

    std::cout << "First matrix: " << std::endl;
    print(a, n, m);

    std::cout << "Second matrix: " << std::endl;
    print(b, x, y);

    int **mult = mulByConst(a, n, m, numb);
    std::cout << "Multiplied by const first matrix: " << std::endl;
    print(mult, n, m);

    if(n == x && m == y){
        std::cout << "Sum of matrix: " << std::endl;
        print(sum, n, m);
    }
}