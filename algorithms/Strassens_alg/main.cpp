#include "func.h"
#include <iostream>

int main () {

	int n = 2;
	std::cout << "Enter the size of matrices(2^n): ";
	std::cin >> n;

	std::cout << "Enter the elemnts of first matrix:" << std::endl;
	int** A = inputMatrix(n);
	std::cout << std::endl;

	std::cout << "Enter the elemnts of second matrix:" << std::endl;
	int** B = inputMatrix(n);
	std::cout << std::endl;

	int** C = mulStrass(A, B, n);

	std::cout << "See they product below:" << std::endl;
	printMatrix(C, n);

	return 0;
}