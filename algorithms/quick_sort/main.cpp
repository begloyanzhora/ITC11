#include <iostream>
#include "func.h"

int main () {
	int arr[5] = {10, 9, 15, 12, 11};
	std::vector<int> vec(arr, arr + 5);

	qSortArr(arr, 0, 4);
	std::cout << "Sorted array: ";
	printArr(arr, 5);

	std::cout << std::endl << "==========================" << std::endl;

	vec = qSortVec (vec);
	std::cout << "Sorted Vector: ";
	printVec(vec);

	std::cout << std::endl;
	return 0;
}