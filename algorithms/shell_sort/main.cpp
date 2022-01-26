#include <iostream>
#include "func.h"

int main () {

	int arr[6] = {5, 85, 4, 21, -12, 15};
	int length = sizeof(arr) / sizeof(*arr);

	shellSort (arr, length);
	printArr(arr, length);

	std::cout << std::endl;

	return 0;
}